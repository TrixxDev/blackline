# Architecture

## Architectural style

BLACKLINE uses a layered, game-driven engine architecture. Dependencies point inward toward small stable contracts. Platform and graphics APIs are implementation details.

```text
Executables
  blackline_client   blackline_server   blackline_editor   tools
          |                 |                  |
          +----------- game/runtime -----------+
                            |
     core  assets  physics  animation  audio  net  ui  render
                            |
                 platform/backend integrations
```

## Target boundaries

Each major subsystem should be a distinct CMake target where practical. Public headers live in an `include/` directory or an intentionally small public tree. Implementation files remain private to the target.

Proposed early targets:

- `bl_core`
- `bl_platform_sdl`
- `bl_rhi`
- `bl_rhi_d3d11`
- `bl_renderer`
- `bl_assets`
- `bl_net`
- `bl_physics`
- `bl_game`
- `blackline_client`
- `blackline_server`
- `bl_tests`

Add targets only as real code appears.

## Ownership and lifetimes

- Prefer value types and RAII.
- Use `std::unique_ptr` for exclusive polymorphic ownership.
- Use non-owning references, spans, and handles for access.
- Avoid shared ownership unless the lifetime is genuinely shared and documented.
- GPU and asset resources use generational handles so stale handles can be detected.
- Avoid global mutable singletons. Application composition owns services explicitly.

## Runtime loop

The client separates rendering from fixed simulation:

```text
poll platform events
accumulate real time
while accumulator >= fixed_dt:
    sample/consume input command
    simulate fixed tick
    accumulator -= fixed_dt
interpolate render state
render frame
present
```

The server runs fixed simulation ticks independently of graphics frame rate.

Initial target tick rates are configuration values, not hardcoded protocol assumptions. Start with 64 Hz for gameplay experiments and measure before changing.

## Threading

Start simple:

- main thread: platform events and high-level coordination;
- render submission: main thread initially;
- server simulation: one authoritative simulation thread initially;
- background jobs: asset I/O and compilation only after the synchronous path works.

Do not introduce a job system before a measured need and a clear ownership model.

## Error handling

- Programming invariant violations: assertions in debug builds.
- Recoverable runtime failures: typed result/error values with context.
- Fatal startup failures: structured log plus clean process exit.
- Exceptions may be used only when a subsystem policy explicitly allows them. Do not throw across DLL/plugin or C ABI boundaries.
- Never ignore API return codes.

## Data orientation

Do not begin with a complex ECS. Early gameplay can use explicit world-owned collections and stable entity IDs. Introduce a data-oriented ECS only when profiling and feature pressure justify it.

## Determinism

Exact cross-platform floating-point determinism is not an initial requirement. Required properties are:

- fixed-tick authoritative simulation;
- deterministic behavior within tested target builds for identical input and initial state where feasible;
- explicit random seeds;
- no wall-clock reads inside simulation logic;
- versioned serialization;
- reproducible headless tests.

## Configuration

- Developer configuration may use human-readable TOML or JSON.
- Gameplay tuning data should be data-driven and validated.
- Network protocol behavior must not depend on unvalidated client configuration.
- Production secrets never belong in repository configuration.

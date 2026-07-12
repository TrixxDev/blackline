# BLACKLINE repository instructions

## Mission

Build BLACKLINE: a competitive round-based network FPS and the purpose-built engine that powers it. Work incrementally. Preserve a buildable, testable repository after every task.

## Canonical repository

- Canonical GitHub repository: `https://github.com/TrixxDev/blackline.git`.
- Expected remote name: `origin`.
- Before repository-wide or bootstrap work, verify `git remote get-url origin` matches the canonical URL.
- Work only inside the checked-out canonical repository. Do not initialize a second repository, create a sibling implementation, replace `.git`, or change remotes.
- Never push, force-push, delete remote branches, rewrite shared history, or change repository visibility/settings unless the owner explicitly asks.
- Preserve all pre-existing user changes. Do not reset, clean, checkout over, stash, or discard them without explicit approval.
- If the current directory is not a clone of the canonical repository, stop and report the mismatch before editing.

## Read before changing code

Always read these files when relevant:

- `PROJECT_CONTEXT.md`
- `PLANS.md`
- `docs/ARCHITECTURE.md`
- `docs/ROADMAP.md`
- `docs/REPOSITORY_WORKFLOW.md`
- `docs/CODING_STANDARDS.md`
- `docs/TESTING.md`
- subsystem documentation under `docs/`
- applicable ADRs under `docs/adr/`

For large or multi-step work, create or update an execution plan using `PLANS.md` before implementation.

## Non-negotiable engineering rules

1. The game and engine evolve together. Do not build a speculative general-purpose engine.
2. Implement the smallest vertical capability that advances the current roadmap milestone.
3. Never couple gameplay code to D3D11, D3D12, Vulkan, SDL, or other platform handles.
4. All rendering calls outside a backend must go through the project RHI.
5. Design the RHI around explicit command submission, resource states, pipelines, descriptors, queues, and synchronization. D3D11 may emulate or ignore unsupported explicit operations.
6. Backend order is D3D11 first, D3D12 second, Vulkan third. Do not implement all three in parallel unless a task explicitly requires parity work.
7. The dedicated server must remain headless and must not link renderer or editor code.
8. The server is authoritative for movement acceptance, shots, damage, deaths, round state, and economy.
9. Simulation-affecting code must be deterministic enough for prediction, reconciliation, replay, and tests. Do not use frame delta directly for authoritative simulation.
10. Use fixed-width integer types at serialization and network boundaries.
11. Do not add a production dependency without documenting the reason in `docs/DEPENDENCIES.md` and recording a decision when architectural.
12. Do not commit generated build output, downloaded SDKs, secrets, caches, or proprietary assets.
13. Never copy assets, names, maps, sounds, code, or trade dress from CS2 or another commercial game.
14. Prefer fictional weapons and factions. Real-world inspiration must not become an exact branded replica without explicit licensing review.
15. Do not claim a feature works until the relevant automated checks and, when applicable, a launch smoke test have passed.

## Expected repository shape

```text
engine/      reusable runtime systems
  core/      application, logging, time, jobs, memory, diagnostics
  platform/  SDL/window/input/platform integration
  render/    RHI contracts, backends, renderer, shaders
  assets/    asset database, import, cooked formats
  physics/   collision and character movement
  animation/ skeletal animation and IK
  audio/     runtime audio
  net/       transport, serialization, snapshots
  ui/        runtime UI abstractions

game/        BLACKLINE gameplay code and data
server/      dedicated authoritative server executable
editor/      tools and level editor executable
tools/       asset cooker, shader compiler wrappers, Blender tooling
assets/      source assets and metadata, never unlicensed content
tests/       cross-module tests and fixtures
docs/        architecture, roadmap, ADRs, workflows
```

Create missing directories only when the current task needs them.

## Build conventions

- Language standard: C++23.
- Build system: modern target-based CMake.
- Dependency management: vcpkg manifest mode.
- Primary development host: 64-bit Windows.
- Supported generators initially: Visual Studio 2022 and Ninja.
- Warnings are errors for project code in CI; third-party warnings must not leak into project targets.
- Keep build presets in `CMakePresets.json` once bootstrap creates them.
- Keep platform-specific source files isolated and named clearly.

Canonical commands after bootstrap should remain documented in `README.md`. Prefer presets such as:

```powershell
cmake --preset windows-debug
cmake --build --preset windows-debug
ctest --preset windows-debug --output-on-failure
```

If commands differ because the repository has evolved, update documentation in the same change.

## Change workflow

Before editing:

1. Verify the canonical remote, then inspect repository state and relevant docs.
2. Identify the narrowest subsystem boundary affected.
3. State assumptions in the execution plan or task notes.
4. Check for existing tests and patterns before introducing new ones.

During implementation:

1. Make coherent, reviewable changes.
2. Add or update tests with behavior changes.
3. Keep public interfaces small and documented.
4. Avoid unrelated cleanup.
5. Record architectural decisions in an ADR.
6. Update roadmap/checklists only after evidence exists.

Before finishing:

1. Format changed project files.
2. Build every affected target.
3. Run focused tests, then the relevant broader suite.
4. Run a smoke test when the task changes startup, rendering, networking, assets, or gameplay.
5. Review the diff for accidental generated files, dead code, debug bypasses, and API leaks.
6. Report exactly what changed, commands run, results, remaining risks, and the next logical task.

## Definition of done

A task is done only when:

- requested behavior is implemented;
- architecture rules remain satisfied;
- tests cover important success and failure paths;
- affected targets build without new warnings;
- documentation matches reality;
- no known blocker is hidden;
- the final report includes reproducible verification commands.

## Stop conditions

Stop and explain rather than guessing when:

- a required SDK/tool is unavailable and no safe local substitute exists;
- licenses are unclear;
- a requested change contradicts an accepted ADR or these instructions;
- the only apparent solution weakens server authority, memory safety, or repository security;
- verification cannot be performed.

When blocked, still leave useful artifacts: analysis, a minimal failing test, a plan, or a narrowly scoped interface.

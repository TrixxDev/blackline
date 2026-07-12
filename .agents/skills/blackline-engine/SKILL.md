---
name: blackline-engine
description: Use for implementing, reviewing, or planning BLACKLINE custom engine, rendering RHI, authoritative networking, FPS movement, weapons, asset pipeline, editor, and vertical-slice tasks. Do not use for unrelated repositories or generic web/mobile work.
---
## Repository boundary

Operate only in the canonical repository `https://github.com/TrixxDev/blackline.git`. Verify `origin` before broad changes. Never create a separate engine repository or nested project root. Preserve user changes and do not push or alter remotes without explicit authorization.


# BLACKLINE engine workflow

## Start

1. Read root `AGENTS.md` and `PROJECT_CONTEXT.md`.
2. Read the active roadmap phase and subsystem documentation.
3. Inspect existing code and tests before proposing abstractions.
4. For multi-step work, use the `PLANS.md` template.

## Scope control

- Build only what the active acceptance criteria need.
- Prefer a working vertical path over broad framework code.
- Do not implement future rendering backends in parallel.
- Do not add production-quality art work before gameplay and asset interfaces are proven.
- Keep headless server dependencies free of renderer/editor/platform-video code.

## Rendering checklist

- No native graphics handles above backend boundaries.
- RHI contract remains compatible with explicit APIs.
- Resource usage, format, lifetime, and state are validated.
- Debug names/markers exist for GPU resources and passes.
- Backend smoke tests and capability reporting are updated.
- Coordinate, clip-space, winding, and depth conventions remain documented and tested.

## Networking checklist

- Server owns outcomes.
- Packets are bounded and versioned.
- Serialization is explicit, not native struct casting.
- Simulation uses fixed ticks.
- Tests cover malformed input and adverse network conditions.
- Client prediction never becomes an authority bypass.

## Gameplay checklist

- Gameplay state and presentation state are separated.
- Weapon actions have validated sequence/tick identity.
- Movement, recoil, and round transitions are data-driven where appropriate.
- Important behavior has headless tests.

## Asset checklist

- Source and cooked data are separate.
- Import/cook is repeatable and versioned.
- Coordinate conversion happens in one importer boundary.
- Asset provenance and licensing are recorded.
- AI/procedural output is treated as prototype until manually validated.

## Finish

- Build all affected targets.
- Run focused and relevant broader tests.
- Run required smoke tests.
- Review for native API leaks, unbounded parsing, stale handles, accidental dependencies, and generated files.
- Report commands and evidence exactly.

# Roadmap

This roadmap is ordered. Do not start later features because they look interesting.

## Phase 0 — repository foundation

Outcome: repeatable empty-project build and test environment.

- [ ] Git repository hygiene and license decision
- [x] CMake project and presets
- [x] vcpkg manifest
- [x] compiler warnings and formatting
- [x] test framework and one passing smoke test
- [x] core library and minimal executable
- [ ] CI for Windows build/test
- [x] developer README with exact setup commands

Exit criteria: clean clone can configure, build, and run tests using documented commands.

Phase 0 local closure (2026-07-13): Debug and Release presets configure, build, pass CTest (4/4), and run `blackline_bootstrap.exe` with version `0.0.1`. Pushed to `origin/main` as commit `61f2bac`.

Remaining open:

- **License decision** — owner has not selected a license (`LICENSE.md` placeholder only).
- **Remote CI validation** — workflow `.github/workflows/windows-ci.yml` is present, but the first run (`Windows Build and Test #1`, commit `61f2bac`) did not start. GitHub reported: *The job was not started because your account is locked due to a billing issue.* This is an account/platform blocker, not evidence of a repository or build defect. Do not create a new commit solely to retrigger CI. After the billing lock is resolved, re-run `Windows Build and Test #1` against commit `61f2bac` and inspect the actual build/test result.

Phase 1 must not start until remote CI validation is complete.

## Phase 1 — platform shell

Outcome: stable application shell without rendering abstraction complexity.

- [ ] logging and diagnostics
- [ ] time and fixed-tick accumulator
- [ ] SDL3 initialization
- [ ] window creation and event loop
- [ ] keyboard/mouse input state
- [ ] clean startup/shutdown and failure paths

Exit criteria: application opens a window, handles input, runs fixed ticks, and exits cleanly under tests/smoke checks.

## Phase 2 — RHI contract and D3D11 bring-up

Outcome: first GPU-rendered frame through project RHI.

- [ ] RHI types and validation
- [ ] backend factory and capability report
- [ ] D3D11 device/swapchain
- [ ] clear frame
- [ ] buffers, shaders, pipeline, indexed triangle
- [ ] debug names and diagnostics
- [ ] resize handling

Exit criteria: D3D11 triangle renders through RHI with no native handles above backend boundary.

## Phase 3 — first 3D scene

Outcome: graybox world rendered and navigable.

- [ ] math and transform conventions
- [ ] depth buffer
- [ ] mesh and texture resources
- [ ] FPS camera
- [ ] glTF static mesh importer
- [ ] cooked mesh format
- [ ] simple PBR material and directional light
- [ ] debug geometry

Exit criteria: player camera moves through a loaded graybox scene at stable frame pacing.

## Phase 4 — collision and character controller

Outcome: deterministic playable movement.

- [ ] collision world representation
- [ ] ray/sweep queries
- [ ] kinematic capsule controller
- [ ] acceleration, friction, jump, crouch
- [ ] steps, slopes, ceiling handling
- [ ] fixed-tick movement tests

Exit criteria: headless movement test suite and in-game debug visualization agree.

## Phase 5 — local weapon prototype

Outcome: one complete local rifle loop.

- [ ] data-driven weapon definition
- [ ] hitscan query
- [ ] ammunition and reload state
- [ ] deterministic recoil pattern
- [ ] separate camera/gameplay/visual recoil
- [ ] impact events and debug effects
- [ ] scripted Blender blockout weapon pipeline

Exit criteria: graybox player can shoot targets with tested weapon state transitions.

## Phase 6 — headless server and transport

Outcome: clients connect to an authoritative simulation.

- [ ] dedicated server target without renderer dependency
- [ ] versioned packet serialization
- [ ] loopback and UDP transports
- [ ] connection lifecycle
- [ ] input command stream
- [ ] snapshots
- [ ] packet loss/jitter test harness

Exit criteria: two local clients connect and receive authoritative world snapshots.

## Phase 7 — prediction, reconciliation, and combat

Outcome: responsive authoritative multiplayer gunfight.

- [ ] local movement prediction
- [ ] reconciliation
- [ ] remote interpolation
- [ ] server-validated fire
- [ ] player history and lag compensation
- [ ] health, death, respawn for test mode
- [ ] network metrics and debug overlays

Exit criteria: two clients can move and kill each other under simulated latency/loss without trusting client outcomes.

## Phase 8 — round mode vertical slice

Outcome: first complete competitive match loop.

- [ ] teams and spawns
- [ ] warmup/freeze/live/post-round state machine
- [ ] no-respawn live rounds
- [ ] plant/defuse objective
- [ ] win conditions
- [ ] economy and buy phase
- [ ] score and side switching
- [ ] deterministic headless match integration test

Exit criteria: one local match can run from start to finish and restart.

## Phase 9 — D3D12 backend

Outcome: modern primary Windows renderer.

- [ ] D3D12 device, queues, swapchain
- [ ] descriptors and upload path
- [ ] resource state tracker
- [ ] frame synchronization and deferred destruction
- [ ] shader DXIL pipeline
- [ ] renderer feature parity
- [ ] PIX/debug-layer clean smoke tests

Exit criteria: vertical slice runs on D3D12 with documented parity and no debug-layer errors.

## Phase 10 — Vulkan backend and Linux

Outcome: cross-platform renderer and build.

- [ ] Vulkan backend foundations
- [ ] SPIR-V shader path
- [ ] renderer parity
- [ ] Linux platform/build fixes
- [ ] validation-clean smoke tests

Exit criteria: vertical slice runs through Vulkan on supported Windows and Linux systems.

## Later phases

- production animation system and IK;
- modular level editor;
- audio propagation and occlusion;
- grenades and penetration;
- replay/demo system;
- bots;
- content production and optimization;
- backend performance work;
- accounts, matchmaking, deployment, observability;
- anti-cheat threat model and defenses;
- original expanded BLACKLINE contract modes.

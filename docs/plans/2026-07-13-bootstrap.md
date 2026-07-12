# Phase 0 repository bootstrap

## Objective

Deliver a reproducible C++23 Windows foundation: CMake presets, vcpkg manifest, `bl_core`, `blackline_bootstrap`, CTest, formatting/static-analysis config, CI workflow, and verified local build/test/run evidence.

## Non-goals

- SDL3, rendering, networking, editor, or gameplay code
- Empty placeholder subsystems beyond the minimal `engine/core` library
- License selection (owner decision recorded in `LICENSE.md`)

## Current state

- Canonical clone at `E:/blackline` with `origin` = `https://github.com/TrixxDev/blackline.git`.
- Phase 0 foundation pushed as commit **`61f2bac`** on `origin/main`.
- Phase 0 closure validation completed locally for Debug and Release presets.
- Remote CI validation remains **open** — first GitHub Actions run did not execute (account billing lock).

## Design

- `bl_core` exposes semantic version and build metadata via `bl::core::version()` and `formatBuildReport()`.
- Catch2 is the only Phase 0 dependency (tests).
- Shared warning/version helpers live in `cmake/BlacklineProjectOptions.cmake`.
- vcpkg toolchain is resolved from `VCPKG_ROOT` in root `CMakeLists.txt`.
- Project version is `0.0.1` for the Phase 0 foundation milestone.

## Milestones

- [x] Restore starter pack after empty clone
- [x] Add CMake/vcpkg/core/bootstrap/tests/tooling/CI files
- [x] Configure, build, test, and run bootstrap executable locally (Debug and Release)
- [x] Align version to `0.0.1` across CMake, tests, and documentation
- [x] Harden `.gitignore` and license placeholder
- [x] Update roadmap checkboxes with verified evidence

## Verification

Debug:

```powershell
cmake --preset windows-debug
cmake --build --preset windows-debug
ctest --preset windows-debug --output-on-failure
.\out\build\windows-debug\apps\bootstrap\blackline_bootstrap.exe
```

Release:

```powershell
cmake --preset windows-release
cmake --build --preset windows-release
ctest --preset windows-release --output-on-failure
.\out\build\windows-release\apps\bootstrap\blackline_bootstrap.exe
```

Local evidence (2026-07-13 closure):

- Toolchain: MSVC **19.51.36246.0** (`cl.exe` from `F:/Microsoft Visual Studio/Product/VC/Tools/MSVC/14.51.36231/bin/Hostx64/x64/cl.exe`) used consistently for vcpkg Catch2 builds and project builds in both presets.
- **windows-debug:** configure/build succeeded; CTest **4/4 passed**; bootstrap reported `version: 0.0.1`, `configuration: Debug`, `compiler: MSVC`.
- **windows-release:** configure/build succeeded; CTest **4/4 passed**; bootstrap reported `version: 0.0.1`, `configuration: Release`, `compiler: MSVC`.
- No Catch2 linker/runtime mismatch observed in either configuration.

## Risks

- **Remote CI blocked (2026-07-13):** GitHub Actions run `Windows Build and Test #1` for commit `61f2bac` did not start. Message: *The job was not started because your account is locked due to a billing issue.* No workflow, CMake, vcpkg, source, or test changes are warranted until a run completes and shows an actual build/test failure.
- License remains unfinalized; see `LICENSE.md`.

## Progress log

- 2026-07-13: Preflight passed (`origin` canonical). Starter pack restored. Phase 0 implemented.
- 2026-07-13: Phase 0 closure — clean Debug/Release validation, version normalized to `0.0.1`, repository hygiene review completed.
- 2026-07-13: Commit `61f2bac` pushed to `https://github.com/TrixxDev/blackline.git`. First Actions run blocked by GitHub account billing lock; remote CI validation deferred.

## Decision log

- Catch2 chosen for Phase 0 tests per `docs/DEPENDENCIES.md`.
- Ninja + single-config presets chosen for the initial Windows developer path.
- vcpkg baseline pinned to `f87344cac03158cbf1467264565f1fd36b382a24`.
- Phase 0 version set to `0.0.1` (no repository document defines `0.1.0` as the bootstrap milestone).

## Completion report

Phase 0 is **locally complete** at commit `61f2bac`. Phase 0 is **not fully closed** until remote CI validation succeeds.

Open items:

- owner license decision;
- re-run `Windows Build and Test #1` on commit `61f2bac` after the GitHub billing lock is resolved (do not push an empty commit to retrigger CI).

Do **not** start Phase 1 until remote CI validation passes.

Next step after billing resolution: re-run the existing workflow, inspect logs, then update this plan and `docs/ROADMAP.md` with the verified remote CI result.

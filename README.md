# BLACKLINE

BLACKLINE is a competitive round-based network FPS and the purpose-built engine that powers it.

This repository is in **Phase 0** (repository foundation), version **0.0.1**. The bootstrap target verifies that the C++23 toolchain, CMake presets, vcpkg manifest mode, core library, tests, and CI workflow wiring are correct.

## Prerequisites

- Windows 10/11 x64
- Visual Studio 2022 or newer with the **Desktop development with C++** workload
- [CMake](https://cmake.org/download/) 3.24 or newer (on `PATH`)
- [Ninja](https://ninja-build.org/) (on `PATH`)
- [vcpkg](https://github.com/microsoft/vcpkg) cloned locally with `VCPKG_ROOT` set to that directory
- Git

## First-time setup

```powershell
git clone https://github.com/TrixxDev/blackline.git
cd blackline

git clone https://github.com/microsoft/vcpkg.git C:\dev\vcpkg
C:\dev\vcpkg\bootstrap-vcpkg.bat
$env:VCPKG_ROOT = "C:\dev\vcpkg"
```

Open a **x64 Native Tools Command Prompt for VS 2022** (or run `vcvars64.bat`) so `cl.exe` is available, then:

```powershell
cmake --preset windows-debug
cmake --build --preset windows-debug
ctest --preset windows-debug --output-on-failure
.\out\build\windows-debug\apps\bootstrap\blackline_bootstrap.exe
```

Release builds use the `windows-release` preset with the same commands, substituting the preset name.

`CMakeLists.txt` discovers the vcpkg toolchain from `VCPKG_ROOT` automatically. Use the **same MSVC developer environment** for vcpkg package builds and project builds to avoid Catch2 linker mismatches.

## Repository layout

```text
engine/core/     bl_core library (version/build metadata)
apps/bootstrap/  blackline_bootstrap console executable
tests/           CTest targets
cmake/           shared CMake helpers
docs/            architecture, roadmap, ADRs
```

## Canonical commands

```powershell
cmake --preset windows-debug
cmake --build --preset windows-debug
ctest --preset windows-debug --output-on-failure
```

## Phase 0 status

Locally verified on 2026-07-13 (commit `61f2bac`):

- Debug and Release presets configure, build, and test cleanly
- `blackline_bootstrap.exe` reports `0.0.1` and the matching configuration name

Remote CI (open):

- Workflow `.github/workflows/windows-ci.yml` is on `main`
- First run (`Windows Build and Test #1`) did **not** execute — GitHub account billing lock
- This is not treated as a repository or build defect; no workflow or code changes were made in response
- After billing is resolved, re-run the same workflow against commit `61f2bac` (no new commit needed to trigger CI)

Phase 1 has not started and remains blocked until remote CI validation completes.

## License

See `LICENSE.md`. Licensing has not been finalized; the placeholder grants no redistribution rights.

## Next milestone

Phase 1 — platform shell (logging, fixed tick, SDL3 window and input). **Blocked** until Phase 0 remote CI validation completes. See `docs/ROADMAP.md`.

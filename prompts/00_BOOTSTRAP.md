# Codex task: bootstrap the BLACKLINE repository

Read `AGENTS.md`, `PROJECT_CONTEXT.md`, `PLANS.md`, `docs/ARCHITECTURE.md`, `docs/CODING_STANDARDS.md`, `docs/TESTING.md`, `docs/DEPENDENCIES.md`, `docs/REPOSITORY_WORKFLOW.md`, and Phase 0 of `docs/ROADMAP.md` before editing.

This task must run inside the canonical clone of `https://github.com/TrixxDev/blackline.git`. Before editing, run `git rev-parse --show-toplevel`, `git status --short --branch`, and `git remote -v`. Confirm that `origin` resolves to the canonical repository. If it does not, stop without modifying files and report the mismatch. Do not run `git init`, replace `.git`, create another repository, or change the remote.

## Objective

Implement Phase 0 only: a clean, reproducible C++23 repository foundation that configures, builds, tests, and runs a minimal console executable on 64-bit Windows.

## Required deliverables

- top-level `CMakeLists.txt` using target-based modern CMake;
- `CMakePresets.json` with documented Windows MSVC Debug and Release presets;
- `vcpkg.json` in manifest mode with only dependencies required by Phase 0;
- `cmake/` helpers only when they reduce duplication;
- `engine/core` library with one small tested utility or version API;
- `blackline_bootstrap` executable that links `bl_core` and prints structured version/build information;
- test target integrated with CTest;
- `.clang-format` and conservative `.clang-tidy`;
- `.editorconfig`, `.gitignore`, and `README.md`;
- GitHub Actions Windows build/test workflow if the repo is hosted on GitHub, otherwise create the workflow file without assuming it has run;
- license choice must not be invented: add a clearly marked owner decision item if no license is provided.

## Constraints

- Do not add SDL, graphics, networking, editor, or game code yet.
- Do not add a dependency when standard C++ is sufficient.
- Do not create empty architecture layers for future phases.
- Warnings must be treated as errors for project targets.
- Do not claim CI passed unless it actually ran; local build/test evidence is separate.

## Execution

1. Verify repository identity and preserve any pre-existing working-tree changes.
2. Create an execution plan using `PLANS.md`.
3. Inspect available compilers, CMake, Ninja, Git, and vcpkg state.
4. Implement the smallest foundation satisfying Phase 0.
5. Configure, build, and test with available documented presets.
6. Run the executable and capture its output.
7. Review the diff.
8. Update `docs/ROADMAP.md` checkboxes only for verified items.
9. Finish with exact commands, results, limitations, and the next recommended task.

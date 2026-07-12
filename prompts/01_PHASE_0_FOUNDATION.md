# Codex task: audit and complete Phase 0

Use this prompt after bootstrap or when inheriting a partially initialized repository.

Read the repository instructions, `docs/REPOSITORY_WORKFLOW.md`, and Phase 0 roadmap. Verify that the workspace is the canonical clone of `https://github.com/TrixxDev/blackline.git` before editing. Audit the existing implementation instead of assuming it is correct. Fix only Phase 0 gaps. Never initialize or migrate to another repository.

Required outcome:

- a fresh documented configure/build/test path works;
- no future-phase placeholder code is needed;
- project warnings are clean;
- CTest discovers and runs tests;
- bootstrap executable runs;
- README setup is accurate;
- roadmap evidence is honest.

First produce a short gap analysis. Then implement, validate, and review. Do not begin SDL or rendering work.

# Codex task: implement Phase 1 platform shell

Before editing, verify that `origin` is `https://github.com/TrixxDev/blackline.git`, inspect the working tree, and preserve all pre-existing changes. Do not push or change remotes unless explicitly requested.


Read all repository instructions and Phase 1 of `docs/ROADMAP.md`.

## Objective

Create the minimal SDL3 application shell with clean lifecycle, input, diagnostics, and a fixed-tick loop. No RHI or graphics backend implementation yet beyond the SDL window surface needed for a visible window.

## Acceptance criteria

- `blackline_client` opens a resizable window and exits cleanly;
- window and SDL ownership are RAII-based;
- keyboard and relative mouse input are represented in project-owned input state/types;
- simulation ticks use a tested fixed-step accumulator;
- resize, focus, quit, and startup failure paths are handled;
- headless unit tests do not require a display;
- application logs backend/platform and timing configuration;
- no native SDL types leak into gameplay-facing public headers;
- documented build/test/run commands work.

Create an execution plan, implement narrowly, test, run a smoke test, review the diff, and update roadmap evidence.

# Codex task: implement Phase 2 RHI and D3D11 bring-up

Before editing, verify that `origin` is `https://github.com/TrixxDev/blackline.git`, inspect the working tree, and preserve all pre-existing changes. Do not push or change remotes unless explicitly requested.


Read `docs/RENDERING_RHI.md`, relevant ADRs, and Phase 2 of the roadmap.

## Objective

Render an indexed triangle through a minimal project-owned RHI using D3D11, while preserving an explicit-API-shaped contract for future D3D12 and Vulkan backends.

## Constraints

- No D3D12 or Vulkan implementation in this task.
- No native D3D11 types outside `engine/render/backends/d3d11` or equivalent private backend tree.
- Add only RHI operations required for clear, buffers, shaders, pipeline, draw, resize, and present.
- Do not create a giant speculative abstraction.
- Enable D3D11 debug diagnostics in development configurations when available.

## Acceptance criteria

- backend selection accepts `-dx11` and reports selected adapter/capabilities;
- clear-screen test works;
- indexed triangle renders;
- resize and minimized-window handling are safe;
- invalid descriptions fail predictably;
- RHI handle lifetime has unit tests;
- client shuts down with no known debug-layer errors;
- exact build, test, and smoke-test commands are documented.

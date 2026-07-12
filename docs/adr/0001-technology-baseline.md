# ADR-0001: Technology baseline

- Status: Accepted
- Date: 2026-07-12

## Context

BLACKLINE requires a custom game engine suitable for a competitive network FPS. The project begins on Windows but should retain a credible Linux/Steam Deck path.

## Decision

- Use C++23 and target 64-bit systems.
- Use CMake with vcpkg manifest mode.
- Use SDL3 for windowing and input.
- Implement a project-owned RHI.
- Support D3D11, D3D12, and Vulkan in that order.
- Design RHI semantics around explicit APIs.
- Use HLSL as canonical shader source with backend-specific compilation.
- Use glTF/GLB as art interchange and custom cooked runtime formats.
- Build a separate headless authoritative server.

## Consequences

Positive:

- fast first rendering result through D3D11;
- modern Windows and cross-platform paths remain possible;
- gameplay is isolated from platform APIs;
- server can be tested without GPU dependencies.

Negative:

- three rendering backends create substantial long-term maintenance cost;
- shader and resource convention parity must be actively tested;
- custom networking, asset tooling, and editor work increase scope.

## Guardrail

Backend work is sequential. A playable feature on one backend is preferred over three incomplete implementations.

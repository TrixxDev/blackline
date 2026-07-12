# Rendering and RHI

## Goals

- Isolate D3D11, D3D12, and Vulkan behind one project-owned RHI.
- Keep gameplay and high-level renderer free of native API types.
- Reach a playable D3D11 renderer quickly without making D3D12/Vulkan impossible.
- Make backend parity observable through tests and captured reference scenes.

## Backend sequence

1. Define the minimum RHI contracts required for clear-screen and triangle tests.
2. Implement D3D11 backend.
3. Build the first functional renderer and graybox scene on D3D11.
4. Stabilize resource/pipeline conventions.
5. Implement D3D12 backend and make it the preferred Windows backend.
6. Implement Vulkan backend and establish Linux build support.

Do not build three backends simultaneously.

## RHI model

The RHI contract uses explicit concepts even when D3D11 hides them:

- instance/adapter selection;
- logical device;
- queues;
- swapchain;
- command list/context;
- buffers and textures;
- resource usage and state;
- graphics/compute pipeline state;
- descriptor/binding layouts;
- samplers;
- render attachments;
- barriers/transitions;
- fences and frame synchronization;
- capabilities query.

## Handle policy

Public RHI APIs expose typed generational handles or narrow abstract objects. Never expose `ID3D11*`, `ID3D12*`, or `Vk*` types above backend boundaries.

Descriptions are plain validated data structures. Example categories:

- `BufferDesc`
- `TextureDesc`
- `SamplerDesc`
- `ShaderModuleDesc`
- `GraphicsPipelineDesc`
- `RenderPassDesc` or dynamic-rendering equivalent abstraction

Avoid copying one native API structure into the cross-platform interface.

## Capabilities

Query capabilities instead of guessing:

- API/backend identity;
- adapter name and memory budget;
- texture and buffer limits;
- supported formats;
- anisotropy;
- timestamp queries;
- compute support;
- bindless/resource indexing support;
- mesh shaders;
- ray tracing;
- variable-rate shading.

The baseline renderer must work without mesh shaders, ray tracing, or bindless resources.

## D3D11 backend

Purpose: fast bring-up and compatibility.

- Use one immediate context initially.
- Map explicit transitions to validation/no-op bookkeeping where the driver owns hazards.
- Maintain binding-state hygiene to prevent resource hazards.
- Compile Shader Model 5-compatible DXBC for this backend.
- Do not let D3D11 convenience dictate high-level renderer architecture.

## D3D12 backend

Purpose: primary modern Windows path.

Required foundations:

- adapter selection;
- command queues and allocators;
- descriptor heap management;
- upload staging;
- explicit resource state tracking;
- per-frame fences;
- deferred destruction;
- memory allocation policy;
- PIX-compatible debug names and markers.

Implement correctness and debug-layer cleanliness before optimization.

## Vulkan backend

Purpose: cross-platform path.

Required foundations:

- validation layers in development;
- physical-device capability selection;
- queues and synchronization;
- swapchain recreation;
- descriptor management;
- explicit layout/state tracking;
- debug names and markers;
- SPIR-V compilation and reflection.

Validation warnings are treated as defects unless documented as verified external issues.

## Shaders

Canonical source language: HLSL.

```text
HLSL source
  -> D3D11 DXBC (SM5 compatible compiler path)
  -> D3D12 DXIL (DXC)
  -> Vulkan SPIR-V (DXC -spirv)
```

Rules:

- Keep source in a common portable subset unless guarded by backend capability variants.
- Shader bindings are generated or reflected into validated metadata.
- Shader compilation is an offline/tool step for shipped builds.
- Development hot reload may be added later.
- Cache keys include source, includes, defines, compiler version, target, and options.

## First rendering milestones

- RHI unit tests for description validation and handle lifetime.
- D3D11 clear-screen executable.
- Indexed colored triangle.
- Depth-tested textured mesh.
- FPS camera and graybox level.
- Basic physically based material.
- Directional light and shadow map.
- Debug lines, collision view, and GPU timing markers.

## Backend parity tests

Create a small deterministic reference scene and compare:

- dimensions and formats;
- projection conventions;
- winding/culling;
- depth range and clear behavior;
- texture sampling;
- blending;
- shader constant layout;
- rendered image within a documented tolerance.

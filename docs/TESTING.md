# Testing and verification

## Test pyramid

1. Unit tests for pure logic, serialization, math, handles, allocators, and validation.
2. Subsystem tests for RHI contracts, asset cooking, collision, and network behavior.
3. Headless integration tests for match flow.
4. GPU smoke tests for each rendering backend.
5. Manual playtests for feel and presentation.

## Required properties

- Tests are deterministic unless explicitly testing randomized behavior.
- Randomized tests log their seed.
- Tests do not require internet access.
- Headless tests do not initialize SDL video or a graphics backend.
- GPU tests skip with a clear reason when hardware/API support is absent; they do not silently pass.
- Flaky tests are defects.

## Build matrix progression

Early:

- Windows MSVC Debug
- Windows MSVC Release

Then:

- Windows clang-cl
- D3D11 GPU smoke test
- D3D12 GPU smoke test
- Linux Clang/GCC
- Vulkan GPU smoke test

## Definition of verification

A task report must include exact commands and results. Examples:

```powershell
cmake --preset windows-debug
cmake --build --preset windows-debug
ctest --preset windows-debug --output-on-failure
```

Renderer changes also require a backend-specific launch or test command. Network/game changes require headless tests.

## Critical test areas

- Generational handles reject stale access.
- Resource descriptions reject invalid combinations.
- Serialization rejects truncation, overflow, and invalid enum values.
- Fixed-tick accumulator behaves under long frames.
- Character controller handles steps, slopes, ceilings, and edge cases.
- Prediction converges after authoritative corrections.
- Lag compensation clamps history correctly.
- Weapon state prevents impossible fire rates and ammunition.
- Round state machine rejects invalid transitions.
- Asset cooker invalidates cache when dependencies change.
- Backend reference scene produces conventionally equivalent output.

## Regression rule

Every fixed bug should receive a regression test when technically feasible. If not feasible, document why and provide another repeatable verification method.

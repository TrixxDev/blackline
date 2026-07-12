# C++ coding standards

## Language

Use C++23 deliberately. Prefer standard-library facilities when they are sufficient and available on supported compilers.

## Naming

- Types and concepts: `PascalCase`
- Functions and local variables: `camelCase`
- Constants: `kPascalCase`
- Private data members: `member_`
- Namespaces: short lowercase hierarchy, for example `bl::render`
- Files: match the primary type or module convention consistently

Do not encode type information in names.

## Headers

- Use `#pragma once` unless a toolchain issue requires guards.
- Include what a header uses.
- Minimize transitive includes.
- Forward-declare only when it improves coupling without making ownership obscure.
- Never place `using namespace` in a header.
- Keep backend/native headers out of public cross-platform headers.

## Interfaces

- Prefer small concrete types over broad inheritance.
- Use abstract interfaces only at real substitution boundaries such as RHI backends or transport implementations.
- Mark important return values `[[nodiscard]]`.
- Use `std::span` for non-owning contiguous ranges.
- Use `std::string_view` for borrowed text where lifetime is clear.
- Use strong enum classes and strong IDs/handles.
- Express units in types or names; never pass ambiguous raw floats for time, angles, or distances.

## Memory and safety

- RAII for all resources.
- No owning raw pointers.
- Avoid manual `new`/`delete` in project code.
- Bounds-check untrusted data before allocation or access.
- No reinterpret-cast serialization.
- Avoid undefined behavior and data races even in performance-sensitive code.
- Use sanitizers on supported configurations.

## Performance

- Optimize after measurement.
- Avoid allocation in known per-frame/per-tick hot paths once profiling identifies them.
- Keep cache-friendly data structures for simulation and rendering batches.
- Document intentional complexity and lifetime assumptions.
- Add benchmarks for important algorithms before aggressive optimization.

## Logging

Structured categories should include at least:

- core
- platform
- render
- assets
- net
- physics
- game
- server
- editor

Do not log every frame or packet at normal levels. Never log secrets or authentication tokens.

## Comments

Explain why, invariants, ownership, units, protocol constraints, and non-obvious API behavior. Do not narrate obvious syntax.

## Formatting and static analysis

Bootstrap should add:

- `.clang-format`;
- `.clang-tidy` with a conservative useful baseline;
- compiler warning policy for MSVC and Clang/GCC;
- optional sanitizers for supported non-MSVC or clang-cl configurations.

Automated formatting must not rewrite third-party code.

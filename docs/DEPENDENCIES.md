# Dependency policy

## Approved initial categories

Exact versions are pinned by vcpkg baseline or repository lock data during bootstrap.

- SDL3: platform windowing and input.
- GLM or a project-selected equivalent: math only after coordinate conventions are documented.
- A small test framework such as Catch2 or GoogleTest.
- Dear ImGui: editor/debug tooling only, not required by the headless server.
- glTF importer library such as fastgltf or cgltf after importer requirements are evaluated.
- Image decoding library for development/import tooling.
- Audio library later, selected by an ADR.

## Rules

Before adding a production dependency, document:

1. Problem it solves.
2. Why standard/project code is insufficient.
3. License and redistribution terms.
4. Supported platforms and compilers.
5. Runtime/build-time footprint.
6. Ownership and update strategy.
7. Alternatives considered.

Dependencies must be isolated behind project-owned boundaries when they represent a replaceable subsystem.

## Prohibited shortcuts

- Do not add a full game engine.
- Do not use a rendering abstraction library that replaces the RHI learning/product goal unless the project owner changes scope.
- Do not import large utility frameworks for one helper function.
- Do not add network libraries that force a trust model incompatible with the authoritative server design without an ADR.
- Do not vendor binaries without source, license, integrity metadata, and platform rationale.

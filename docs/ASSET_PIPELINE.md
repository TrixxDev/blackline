# Asset pipeline

## Goals

- Keep source art editable.
- Import through documented interchange formats.
- Cook assets into fast, versioned runtime formats.
- Track origin and license metadata.
- Support repeatable command-line builds and editor previews.

## Source and interchange formats

- Blender source: `.blend`
- Mesh/scene interchange: `.glb` / glTF 2.0
- Optional collaboration interchange: `.fbx` only when required
- Textures: lossless source formats; cooked GPU formats for runtime
- Audio: lossless source; cooked runtime compression
- Metadata: project-owned sidecar files

The game never loads `.blend` directly.

## Proposed flow

```text
source asset
  -> validation/export
  -> importer
  -> normalized intermediate data
  -> cooker
  -> versioned runtime asset
  -> asset database/cache
```

Every cooked asset records:

- format version;
- content hash;
- source dependencies;
- import settings;
- tool/compiler version;
- platform/backend target where relevant.

## Weapons

Each production weapon may contain:

- first-person view model;
- lower-detail world model;
- collision/interaction shapes;
- skeleton;
- animated parts such as magazine, bolt, trigger, charging handle, stock, and attachments;
- sockets for muzzle, casing ejection, left/right hand IK, optics, suppressor, magazine, and inventory attachment;
- materials and PBR textures;
- animation clips;
- LOD metadata.

Gameplay recoil, camera recoil, and visual weapon animation remain separate systems.

## Characters

- full third-person body model;
- separate first-person arms initially;
- stable humanoid skeleton conventions;
- weapon and equipment sockets;
- simplified server hitboxes independent of render mesh;
- animation clips, blend data, masks, and events;
- later IK and procedural aim offsets.

## Blender automation

Repository Blender scripts belong under `tools/blender/` and must:

- be deterministic where possible;
- use named collections and objects;
- set units and coordinate conventions explicitly;
- establish pivots and sockets;
- validate transforms, normals, UVs, material slots, and missing textures;
- export to a predictable staging path;
- write a machine-readable report;
- fail with a non-zero status on validation errors.

AI-generated procedural models are acceptable for prototype blockouts. They are not automatically production-ready.

## Coordinate conventions

The project must select and document one engine convention before model import implementation. The importer performs conversion from glTF conventions. Never scatter axis/handedness conversion throughout runtime code.

## Prototype asset rules

- Every external asset includes origin, author, license, and permitted use metadata.
- Assets with uncertain licensing remain local and uncommitted.
- Do not use ripped game assets.
- Placeholder assets are visibly marked and listed in `assets/PLACEHOLDERS.md`.
- Production builds fail if prohibited placeholder flags remain.

## First asset milestones

1. Generate a scripted graybox rifle in Blender.
2. Export separate receiver, magazine, bolt, and muzzle socket to GLB.
3. Import static mesh and material metadata.
4. Cook into project binary mesh format.
5. Render the rifle as a world model.
6. Add simple skeleton and reload animation.
7. Add first-person arms and IK sockets.
8. Add automated asset validation tests.

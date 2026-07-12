# BLACKLINE project context

## Repository identity

- Project repository: `https://github.com/TrixxDev/blackline.git`
- Expected local remote: `origin`
- All engine, game, server, editor, tools, documentation, CI, and asset-pipeline work belongs in this repository.
- Do not create a separate `blackline-engine` repository. The purpose-built engine is part of the BLACKLINE monorepo.

## Product vision

BLACKLINE is a competitive first-person tactical shooter built around short rounds, high lethality, economy, information control, and objective play. It should be easy to understand, difficult to master, readable for spectators, and technically suitable for authoritative online matches.

The project intentionally includes a custom engine. The engine is not a standalone product; it exists to serve BLACKLINE.

## Initial game identity

- Competitive teams, initially designed for 5v5.
- Round-based play with no respawn during a live round.
- Primary launch mode begins with a classic two-site plant/defuse ruleset.
- Later modes may add extraction, sabotage, theft, and infrastructure control.
- Gunplay emphasizes first-shot accuracy, learnable recoil, movement penalties, readable audio, and high consequence.
- No hero ultimates, magic, stat progression, or pay-to-win equipment.
- Visual setting: near-future private security conflict around infrastructure and industrial sites.
- Weapons, factions, markings, and environments should be original fictional designs.

## Technical vision

- C++23 codebase.
- Custom runtime and editor.
- SDL3 for windowing and input integration.
- Custom Render Hardware Interface.
- Rendering backends: D3D11, D3D12, Vulkan.
- D3D11 is the first implementation for fast bring-up.
- D3D12 is the main Windows backend after the renderer stabilizes.
- Vulkan is the cross-platform backend and future Linux/Steam Deck path.
- HLSL is the canonical shader language:
  - D3D11: DXBC via FXC/D3DCompile-compatible path;
  - D3D12: DXIL via DXC;
  - Vulkan: SPIR-V via DXC `-spirv`.
- glTF/GLB is the interchange format for meshes, skeletons, materials, and animation.
- Runtime uses cooked, versioned binary assets rather than parsing source formats every launch.
- Dedicated headless authoritative server.
- UDP-based game protocol, eventually with prediction, reconciliation, interpolation, lag compensation, and replayable input/state history.

## Product constraints

- Small-team scope: every system must justify its cost.
- Build a graybox vertical slice before high-fidelity art.
- One map, one rifle, one pistol, one grenade, one objective mode before content expansion.
- Performance work is evidence-driven; profile before optimizing.
- Cross-backend parity is tested, not assumed.
- Competitive integrity outranks visual spectacle.
- Destruction, advanced lighting, matchmaking, anti-cheat, cosmetics, and marketplace features are later milestones.

## First playable target

The first meaningful vertical slice is complete when:

1. A client starts and selects D3D11.
2. A separate headless server starts.
3. Two clients connect locally.
4. Players spawn in a graybox map.
5. Movement is predicted locally and reconciled by the server.
6. A hitscan rifle fires using server-validated shot timing and geometry.
7. Damage can kill a player.
8. The round ends and restarts.
9. A deterministic integration test covers the core match flow without a GPU.

## Art strategy

Prototype content:

- primitives and scripted Blender blockouts;
- temporary humanoid model with verified license;
- simple placeholder animations;
- basic PBR materials;
- no production promise attached to prototype assets.

Production content:

- original first-person arms and weapons;
- separate first-person and world models;
- authored skeletons, sockets, animations, collision meshes, and LODs;
- modular environment kit;
- documented source and license metadata for every third-party asset.

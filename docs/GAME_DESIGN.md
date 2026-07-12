# Game design baseline

## Core pillars

1. Mechanical clarity: players understand why a shot, death, or objective result occurred.
2. Information as a resource: sound, timing, map control, and utility create decisions.
3. High consequence: death matters and rounds remain tense.
4. Learnable mastery: recoil, movement, utility, and maps reward practice.
5. Competitive integrity: no gameplay advantage from monetization.

## First mode

The first implementation is a conservative two-site plant/defuse mode because it provides a clear technical vertical slice.

Initial parameters are tuning data, not permanent constants:

- two teams;
- five players per team target, but local tests may use fewer;
- freeze/buy period;
- live round timer;
- one objective carrier/device;
- plant and defuse interactions;
- no respawn during live round;
- team switch and match score.

## Weapons for vertical slice

- Rifle: primary automatic hitscan weapon with learnable recoil.
- Pistol: fallback semi-automatic weapon.
- Grenade: delayed projectile/area effect added after basic combat stability.

Each weapon has:

- immutable definition data;
- authoritative runtime state;
- client presentation state;
- first-person and world presentation assets;
- deterministic action sequence IDs for networking.

## Movement baseline

- walking/running;
- crouch;
- jump;
- acceleration and friction;
- movement inaccuracy;
- no wall-running, sliding, grappling, or hero mobility in the baseline.

## Originality boundaries

BLACKLINE may learn from the tactical FPS genre, but must not reproduce protected expression from another game. Avoid copied map layouts, names, iconography, UI composition, audio, weapon skins, animations, and branded fictional elements.

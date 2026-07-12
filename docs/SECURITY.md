# Security and competitive integrity baseline

## Scope

Security is designed from the start, even though production anti-cheat is not an early milestone.

## Trust boundaries

Untrusted:

- all client packets and timing claims;
- asset files downloaded from external sources;
- map/user-generated content;
- configuration supplied by remote services;
- replay and save files.

Trusted only after validation:

- server state transitions;
- cooked assets created by verified tools;
- authenticated service responses in later phases.

## Rules

- Parse bounded data defensively.
- Use integer overflow checks for sizes and offsets.
- Rate-limit connection and gameplay messages.
- Do not reveal sensitive server state to clients unnecessarily.
- Separate debug/admin commands from production protocol.
- Never embed service secrets in client binaries or repository files.
- Keep dependency and asset provenance auditable.
- Use server authority as the first anti-cheat layer.

## Future threat model areas

- movement and fire automation;
- information disclosure/wallhacks;
- packet manipulation and replay;
- account abuse;
- malicious user-generated assets;
- denial of service;
- server binary and deployment security;
- client integrity and telemetry privacy.

Do not add invasive anti-cheat components without a written threat model, legal/privacy review, and explicit owner approval.

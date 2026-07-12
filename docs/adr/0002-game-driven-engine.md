# ADR-0002: Game-driven engine scope

- Status: Accepted
- Date: 2026-07-12

## Context

Building a reusable universal engine before gameplay would create speculative abstractions and delay validation.

## Decision

The engine is developed only in response to BLACKLINE vertical-slice requirements. Generalization is permitted after at least two real uses demonstrate a stable common abstraction.

## Consequences

- Early code may be less generic but more testable and relevant.
- Refactoring is expected when real requirements appear.
- Features not required by the active roadmap phase are deferred.

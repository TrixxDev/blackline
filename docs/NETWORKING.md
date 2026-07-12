# Networking architecture

## Principles

- Dedicated server is authoritative.
- Client sends input commands and intent, never trusted outcomes.
- Protocol is binary, versioned, bounded, and fuzz-testable.
- Network code is independent of rendering.
- The same simulation code is reused by server and client prediction where safe.

## Initial topology

```text
Client A -- UDP -- Dedicated server -- UDP -- Client B
```

Local development begins with loopback. Internet services, accounts, matchmaking, relay, and anti-cheat are later systems.

## Simulation model

Client:

- samples input;
- assigns sequence/tick identifiers;
- predicts local movement;
- sends redundant recent input commands;
- receives authoritative snapshots;
- reconciles local state;
- interpolates remote entities.

Server:

- validates packet structure and rate;
- consumes bounded input queues;
- simulates fixed ticks;
- validates movement and actions;
- evaluates shots and damage;
- emits snapshots/events;
- owns round and economy state.

## Protocol rules

- Explicit byte order.
- Fixed-width fields at the wire boundary.
- Length-prefix variable data and enforce maxima before allocation.
- Never deserialize directly into native structs with padding.
- Every message has a protocol version and type.
- Reject malformed, stale, impossible, or excessive input safely.
- Separate reliable game events from high-frequency state snapshots.
- Authentication and encryption are later milestones but protocol boundaries must allow them.

## Transport progression

1. In-process deterministic transport for tests.
2. Loopback UDP transport.
3. Sequence numbers, acknowledgements, packet loss metrics.
4. Reliable ordered channel for critical low-rate events.
5. Snapshot delta compression.
6. Bandwidth and abuse limits.
7. Internet/NAT/relay strategy after the vertical slice.

## Shooting

The client reports a shot intent containing weapon/action sequence and timing data. The server verifies:

- player state permits firing;
- weapon cooldown and ammunition;
- origin/direction are consistent with authoritative state and allowed view history;
- timestamp falls inside the lag-compensation window;
- ray/penetration result against rewound historical hitboxes;
- damage and death.

Never accept client-supplied target or damage.

## Lag compensation

Store a bounded server history of collision-relevant player state. Rewind only the hit-test representation, not the entire mutable world. Clamp requested time to the accepted history window and record metrics for abuse detection.

## Tests

Required test classes:

- serialization round trips;
- malformed and truncated packets;
- maximum lengths and counts;
- reordering, duplication, loss, and jitter simulation;
- prediction/reconciliation convergence;
- shot validation and rewind boundaries;
- headless two-client round integration test;
- deterministic replay of captured input sequences.

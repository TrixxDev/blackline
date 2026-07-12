# Execution plans

Use an execution plan for work that spans multiple files, subsystems, or verification stages. Keep the plan in the task response or create `docs/plans/<yyyy-mm-dd>-<topic>.md` for work expected to continue across sessions.

## Required template

```markdown
# <Plan title>

## Objective
A precise, testable outcome.

## Non-goals
What this task deliberately will not implement.

## Current state
Relevant code, docs, constraints, and known failures.

## Design
Interfaces, ownership, data flow, lifecycle, threading, error handling, and alternatives rejected.

## Milestones
- [ ] Small independently verifiable step
- [ ] Next step

## Verification
Exact build, test, static-analysis, and smoke-test commands.

## Risks
Technical, compatibility, performance, licensing, and migration risks.

## Progress log
- YYYY-MM-DD: evidence-based update.

## Decision log
- Decision and rationale.

## Completion report
What changed, evidence, known limitations, and next task.
```

## Plan discipline

- Plans are living documents, not speculative essays.
- Mark a milestone complete only after verification.
- Record deviations and reasons.
- Never silently reduce acceptance criteria.
- If a plan reveals an architecture decision, add an ADR.
- Keep future phases at high level; detail only the active phase.

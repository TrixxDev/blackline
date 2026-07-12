# Repository workflow

## Canonical identity

BLACKLINE has one canonical source repository:

```text
https://github.com/TrixxDev/blackline.git
```

The expected local remote is `origin`. Engine and game code live together in this repository. No separate engine repository should be created.

## Required preflight

Before any bootstrap, architecture migration, dependency update, or multi-file task, run:

```powershell
git rev-parse --show-toplevel
git status --short --branch
git remote -v
```

Then verify:

```powershell
git remote get-url origin
```

Expected URL:

```text
https://github.com/TrixxDev/blackline.git
```

SSH form `git@github.com:TrixxDev/blackline.git` is acceptable when it resolves to the same repository and was configured by the owner. Do not change HTTPS to SSH or vice versa without being asked.

## Working-tree safety

- Treat every existing uncommitted file as owner work.
- Do not use destructive commands such as `git reset --hard`, `git clean -fdx`, forced checkout, or history rewrite.
- Do not silently stash user changes.
- Inspect diffs before and after implementation.
- Keep generated build output outside tracked source directories when practical.

## Branches and commits

- Continue on the currently selected owner branch unless the task explicitly asks for a new branch.
- Use a focused branch only when requested or when the active workflow already requires it.
- Do not create commits unless the task asks for commits or the owner has established an auto-commit workflow.
- When committing, keep commits coherent and include verification evidence in the final report.

## Remote operations

The following require explicit owner authorization:

- `git push`;
- force-push;
- deleting or renaming remote branches;
- changing `origin`;
- adding a new remote;
- creating releases or tags intended for publication;
- modifying repository settings, visibility, secrets, environments, or branch protection.

Fetching and reading remote state is allowed when network access is available and the task benefits from it. Never claim remote CI passed without observing the actual run.

## Empty-repository bootstrap

If the canonical repository contains only this instruction pack, implement Phase 0 directly in the current clone. Do not create a nested `blackline/` directory. The repository root itself is the project root.

Correct:

```text
<clone-root>/CMakeLists.txt
<clone-root>/engine/
<clone-root>/game/
```

Incorrect:

```text
<clone-root>/blackline/CMakeLists.txt
```

## Mismatch handling

If the workspace is not the canonical clone, or the remote points elsewhere:

1. Make no source changes.
2. Report the actual repository root and remotes.
3. Ask the owner to open or clone the canonical repository.
4. Do not attempt to repair repository identity automatically.

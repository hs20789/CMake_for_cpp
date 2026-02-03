# Commit Convention

Format:
`type(scope): subject`

Rules:
- `type` is required.
- `scope` is optional (use a short area like `cmake`, `docs`, `core`).
- `subject` should be short, imperative, and lowercase.
- Keep the first line within 72 characters when possible.

Allowed types:
- `feat`     new feature
- `fix`      bug fix
- `docs`     documentation only
- `style`    formatting, no logic change
- `refactor` code change that is neither fix nor feat
- `perf`     performance improvement
- `test`     add or update tests
- `build`    build system or external deps
- `ci`       CI configuration
- `chore`    maintenance tasks
- `revert`   revert a previous commit

Examples:
- `feat(parser): add token stream`
- `fix(cmake): guard missing target`
- `docs: add commit convention`

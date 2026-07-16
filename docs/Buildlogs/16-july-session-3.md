# Build Log – 16 July 2026 (Session 3)

## Duration 3:00 pm to 6:00 pm

## Goal
Implement, integrate, and debug the crawler resume functionality while improving the reliability of database operations.

---

## Tasks Completed

### Continue Crawl
- Implemented the `Continue()` functionality to resume crawling after an interrupted execution.
- Retrieved the last pending frontier record from the database along with its associated Seed ID, current depth, and maximum crawl depth.
- Restored the crawler state before restarting the crawl loop.
- Reused the previously stored HTML for the seed page whenever applicable to avoid unnecessary downloads.
- Integrated the resume workflow with the existing crawling pipeline so that the crawler continues from the saved state instead of starting from scratch.

### Frontier Backup
- Implemented `Frontier::backup()` to reconstruct the in-memory queue from the persistent frontier stored in the database.
- Restored pending URLs along with their corresponding depth values.
- Removed restored entries from the database while rebuilding the queue to avoid duplicate processing.
- Added validation for empty frontier conditions before initiating the restore process.

### Database Improvements
- Replaced raw SQL string concatenation with prepared statements for critical database operations.
- Improved the reliability of frontier insertion by safely handling URLs containing special characters.
- Enhanced database retrieval methods to fetch the last pending frontier record along with all required metadata for resuming the crawl.
- Improved error handling for empty query results and invalid database responses.

---

## Bugs Encountered

### Bug 1 – Resume Exceeded Maximum Crawl Depth
**Issue**
- During resume, the crawler continued crawling beyond the maximum depth configured for the original crawl.

**Investigation**
- Traced the issue to incorrect restoration and propagation of the stored maximum depth during the resume workflow.

**Status**
- Root cause identified and debugging performed.

---

### Bug 2 – Frontier Backup Logic
**Issue**
- The backup mechanism exited unexpectedly and failed to restore all pending frontier entries.

**Investigation**
- Found an issue in the control flow of the backup loop that caused premature termination.

**Status**
- Fixed by correcting the backup logic.

---

### Bug 3 – SQL Errors Due to Malformed URLs
**Issue**
- SQL syntax errors occurred while storing frontier records containing malformed URLs or unexpected special characters.

**Investigation**
- Determined that raw SQL query construction was vulnerable to malformed input.

**Status**
- Database operations were migrated to prepared statements. URL parsing and normalization are still being investigated.

---

## Outcome

- Successfully implemented the initial version of the crawler resume mechanism.
- Frontier state can now be restored from the database before continuing execution.
- Database operations are more robust after migrating to prepared statements.
- Resume workflow is functional, with remaining work focused on enforcing maximum crawl depth correctly and resolving malformed URL generation during parsing.
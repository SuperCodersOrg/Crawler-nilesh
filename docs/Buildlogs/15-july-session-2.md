# Build Log – 15 July 2026 session 2

### Duration: 2:30 PM to 5:00 PM



### Goal

* Perform comprehensive testing of all completed core modules.
* Validate the correctness and stability of each component before integrating them into the complete Web Crawler.

---

## Database Testing

### Problem

* Verify that the database correctly stores and retrieves crawled pages.
* Ensure database operations remain stable for different input cases.

### What I Tried

* Tested database initialization and connection.
* Verified page insertion into the database.
* Tested retrieval of stored pages.
* Checked behavior with invalid and empty inputs.
* Repeated operations multiple times to ensure consistency.

### Outcome

* Database operations worked as expected.
* Data was stored and retrieved successfully without inconsistencies.

---

## Queue Testing

### Problem

* Ensure the custom Queue implementation follows FIFO order.
* Validate behavior for normal as well as edge-case operations.

### What I Tried

* Tested enqueue and dequeue operations.
* Verified front(), empty(), and size() functions.
* Tested queue behavior after multiple insertions and deletions.
* Checked dequeue operation on an empty queue.

### Outcome

* Queue behaved correctly in all tested scenarios.
* FIFO ordering was maintained successfully.

---

## Set Testing

### Problem

* Validate correctness of the Set implementation built on top of the custom HashMap.
* Ensure duplicate elements are not stored.

### What I Tried

* Tested insert(), exists(), remove(), clear(), and getAll() functions.
* Verified duplicate insertion handling.
* Checked retrieval of all stored values.
* Tested removal of existing and non-existing elements.

### Outcome

* All Set operations worked correctly.
* Duplicate values were prevented as expected.

---

## URL Normalizer Testing

### Problem

* Ensure different representations of the same URL are normalized consistently.
* Validate handling of various URL edge cases.

### What I Tried

* Tested URLs containing uppercase domains.
* Verified fragment (`#`) removal.
* Tested duplicate slash removal.
* Tested path normalization using `.` and `..`.
* Verified handling of default ports and trailing slashes.
* Compared normalized outputs for equivalent URLs.

### Outcome

* URL Normalizer produced consistent normalized URLs.
* All tested edge cases were handled successfully.

---

## Final Outcome

* Successfully completed testing of the Database, Queue, Set, and URL Normalizer modules.
* Verified that each module functions correctly under both normal and edge-case conditions.
* Resolved minor validation issues identified during testing.
* All completed components are now stable and ready for integration into the complete Web Crawler workflow.

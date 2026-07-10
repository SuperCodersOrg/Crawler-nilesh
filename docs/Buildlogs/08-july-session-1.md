# Build Log – 8 July 2026 (Session 1)

## Objective

Update the Web Crawler design proposal to Version 2 and improve the storage architecture for downloaded webpages.

---

## Work Completed

### 1. Design Proposal Version 2

Updated the Web Crawler Design Proposal from Version 1 to Version 2 to match the current implementation.

Key updates include:

* Updated the crawler architecture.
* Replaced the Downloader design to use **Chrome DevTools Protocol (CDP)** instead of the earlier approach.
* Updated the Frontier interface and URL management design.
* Revised the failure handling and complexity analysis sections.
* Improved the overall modular architecture and future compatibility section.

---

### 2. SQLite Study and Integration

Studied the fundamentals of **SQLite** and understood how it can be integrated into a C++ application for persistent storage.

Learned about:

* Creating and opening SQLite databases.
* Storing and retrieving webpage data.
* Managing database connections.
* Benefits of persistent storage over in-memory data structures.

---

### 3. Page Storage Design Update

Initially, the `PageStorage` component was designed using a `DynamicArray<PageData>` to store downloaded pages in memory.

After evaluating the project requirements, the design was updated to use **SQLite** instead of a `DynamicArray`.

The new design stores each webpage as a database record containing:

* URL
* Rendered HTML
* Crawling Depth

This change provides persistent storage, allows data to survive after program termination, and makes the stored pages directly reusable by future components such as the Indexer.

---

## Outcome

The crawler design is now better aligned with the actual implementation. The storage layer has been redesigned around SQLite, improving scalability, persistence, and compatibility with future project phases.

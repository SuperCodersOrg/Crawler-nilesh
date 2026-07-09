# Build Log – 8 July 2026 - Session 2

## Objective

Implement the initial SQLite-based storage layer and begin the URL normalization module by parsing URL components.

---

## Work Completed

### 1. SQLite Implementation

Implemented the SQLite integration for the `PageStorage` component.

Completed tasks include:

* Integrated the SQLite library into the project.
* Established database connectivity.
* Designed the storage layer to persist downloaded webpages instead of keeping them only in memory.
* Prepared the foundation for storing page information such as URL, rendered HTML, and crawling depth.

This implementation replaces the earlier in-memory storage approach and enables persistent storage for future project phases.

---

### 2. URL Normalizer – Scheme Parsing

Started implementing the URL normalization module inside the `Frontier` component.

Implemented the following method:

```cpp
string parseScheme(string source);
```

#### Purpose

The `parseScheme()` method extracts the **scheme** (protocol) from a URL. This method is used by the URL normalizer to separate the protocol from the remaining URL components before normalization.

Examples:

* `https://example.com` → `https`
* `http://example.com` → `http`
* `ftp://example.com` → `ftp`

This serves as one of the initial parsing functions required for URL normalization.

---

## Outcome

The project now includes an initial SQLite-based persistent storage layer and the first component of the URL normalizer. These implementations provide the foundation for efficient webpage storage and standardized URL processing in subsequent development sessions.

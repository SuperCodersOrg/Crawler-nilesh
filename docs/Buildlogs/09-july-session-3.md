# Build Log – 9 July 2026 (Session 3)

**Duration:** 4:00 PM – 6:00 PM

### Goal

Implement a custom `Set` data structure using the existing `HashMap` implementation and use it for efficient URL existence checking in the web crawler.

### Background

While working on the crawler, I needed a lightweight data structure to keep track of URLs that had already been discovered or processed. The primary requirement was to quickly determine whether a URL already exists so that duplicate URLs are not inserted into the frontier or processed multiple times.

Since the project already contains a custom `HashMap` implementation, building a `Set` on top of it was a natural choice. A set only stores unique elements, and internally it can be implemented using a hash map where each key is associated with a dummy value.

### Why I Chose This Approach

Instead of creating a completely new data structure from scratch, I reused the existing `HashMap` implementation. This reduced code duplication and allowed the `Set` to inherit the average **O(1)** performance for insertion, deletion, and lookup operations.

Internally, each element is stored as the key in the hash map, while a boolean value is used as a placeholder since only the existence of the key matters.

### Implementation

Implemented the following operations in the custom `Set` class:

* `insert()`
* `exists()`
* `remove()`
* `size()`
* `getAll()`
* `clear()`

The implementation delegates all major operations to the underlying `HashMap`. For retrieving all stored elements, the `Set` internally calls the `HashMap::getkeys()` method implemented in the previous session, making the design simple and reusable.

### Problem Encountered

While implementing the `remove()` operation, compilation errors were encountered inside the `HashMap`.

The issue was that the linked list used for collision handling exposed a `remove()` function that removed elements using an **index**, whereas the `HashMap` implementation was attempting to remove an entire `Pair` object directly. Since the method signatures did not match, the compiler reported a type mismatch error.

### Root Cause Analysis

The `HashMap` stores elements inside linked lists as `Pair` objects. During deletion, the correct node had to be located first, and the linked list's `remove()` function expected the index of that node rather than the node's data itself.

This mismatch between the `HashMap` implementation and the linked list API caused the compilation failure.

### Fix Applied

Updated the removal logic inside the `HashMap` to work with the linked list's current interface. Instead of attempting to remove a `Pair` directly, the implementation now identifies the correct node position and invokes the linked list's `remove(index)` method accordingly.

After applying this fix, the `Set` implementation compiled successfully and all operations were able to use the underlying `HashMap` without interface conflicts.

### Integration

The newly implemented `Set` is intended to be used by the web crawler for URL deduplication. Before inserting a newly discovered URL into the frontier, the crawler can check whether the URL already exists in the `Set`. This prevents duplicate processing and improves crawling efficiency.

### Outcome

Successfully implemented a reusable custom `Set` using the existing `HashMap` implementation. Resolved the compatibility issue between the `HashMap` deletion logic and the linked list removal interface. The `Set` is now ready to be integrated into the crawler for maintaining the collection of visited or discovered URLs efficiently.

### Learning

This implementation highlighted the importance of designing compatible interfaces between dependent data structures. Even though the individual data structures were implemented correctly, a mismatch in expected function behavior between the `HashMap` and the linked list caused integration issues. Fixing this improved the overall consistency of the data structure library and made the `HashMap` easier to build upon for higher-level abstractions like `Set`.

# Build Log – 9 July 2026 (Session 2)

**Duration:** 2:00 PM – 4:00 PM

### Goal

Implement a mechanism to retrieve all keys stored in the custom `HashMap` and integrate the same functionality into the Redis-lite project.

### Background

While working on the custom `Set` implementation, I realized that the underlying `HashMap` did not expose any functionality to retrieve all stored keys. Since `Set` internally stores only keys, iterating over every stored element was a necessary requirement. The same limitation was also preventing progress in the Redis-lite project, where several operations require access to the complete collection of keys.

### Problem

The existing `HashMap` API only supported operations such as insertion, lookup, update, deletion, and checking for key existence. There was no public interface to enumerate every key stored in the hash table. Without this capability, higher-level components like `Set` and Redis-lite could not be implemented cleanly and would have required direct access to the internal bucket structure, which would break encapsulation.

### Root Cause Analysis

The `HashMap` uses **separate chaining** to resolve collisions. Each bucket stores a linked list of key-value pairs instead of a single element. Initially, it appeared that reading the first node of every bucket might be sufficient, but after analyzing the collision handling mechanism, it became clear that multiple keys can reside in the same bucket. Therefore, returning only the head node would produce incomplete results whenever collisions occurred.

### What I Implemented

Introduced a new public API:

* `DynamicArray<K> getkeys();`

The implementation iterates through every bucket of the hash table, traverses the complete linked list associated with each bucket, extracts every key stored in the map, and returns them inside a `DynamicArray`. This approach guarantees that every key is returned regardless of how many collisions occur.

### Design Decision

Instead of exposing the internal buckets or linked lists to external classes, I chose to add a dedicated `getkeys()` method to the `HashMap`. This keeps the internal implementation encapsulated while providing a reusable interface that can be used by multiple projects and data structures without exposing implementation details.

### Redis-lite Integration

After completing the implementation in the data structure library, I integrated the same functionality into the Redis-lite project. The Redis-lite application can now retrieve all stored keys directly through the `HashMap` interface instead of depending on internal implementation details. This also prepares the project for implementing commands that operate on the complete key set.

### Challenges Faced

During implementation, I initially treated each bucket as if it contained only a single key-value pair. After reviewing the bucket structure, I realized that each bucket actually represents a linked list because of collision handling. The implementation was modified to traverse every node in every bucket to ensure no stored key is skipped.

### Outcome

Successfully implemented and integrated the `getkeys()` functionality. The custom `HashMap` now supports complete key enumeration, removing a major limitation that was blocking both the `Set` implementation and Redis-lite development. The solution is reusable, maintains proper encapsulation, and will simplify future features that require iteration over all stored keys.

### Learning

This task reinforced the importance of understanding the internal organization of hash tables using separate chaining. Although multiple elements may belong to the same bucket, each element still represents a unique key-value pair and must be traversed individually to produce complete and correct results.

# Build Log – 9 july - session 1 
### Duration 10am - 1pm


## Objective

Implement the `URL Normalizer` component for the web crawler. The objective was to convert different representations of the same URL into a canonical form before inserting them into the frontier, preventing duplicate URLs from being crawled.

---

## Implementation

Implemented the following helper functions inside the `Frontier` class:

### `To_lower(string &link)`

* Converted the complete URL to lowercase to ensure case-insensitive comparison of the scheme and hostname.

### `removeFragment(string &source)`

* Removed the fragment identifier (`#...`) from the URL since fragments do not represent different resources on the server.

### `normalizePath(string &source)`

* Parsed the URL path using `stringstream`.
* Ignored empty path segments and `"."`.
* Resolved `".."` by removing the previous directory from the path stack.
* Reconstructed the normalized path from the processed path components.

### `normalizer(string &source)`

* Extracted the URL scheme, authority, and path.
* Removed default ports (`80` for HTTP and `443` for HTTPS).
* Invoked path normalization.
* Reconstructed the normalized canonical URL.

---

## Issues Encountered

### 1. Incorrect Default Port Removal

While testing the normalizer using the following URL:

```text
Input:
HTTP://Example.COM:80/a/./b/../c//index.html#abc

Expected Output:
http://example.com/a/c/index.html/

Actual Output:
http://example.com:80index.html/
```

The default HTTP port (`:80`) was not removed from the URL.

#### Root Cause

The condition used to identify the default HTTP port was written incorrectly:

```cpp
(port == "8080" && scheme == "http")
```

Instead of checking for port `80`, the implementation was mistakenly comparing against `8080`. As a result, the normalizer never recognized `:80` as the default port and preserved it in the final URL.

#### Resolution

Updated the condition to:

```cpp
(port == "80" && scheme == "http")
```

After correcting the comparison, the default HTTP port was removed successfully and the authority section was generated correctly.

---

### 2. Incorrect Path Reconstruction

After fixing the port issue, the normalized path was still incorrect because only the last path component was retained.

#### Root Cause

While rebuilding the normalized path, the following statement was used:

```cpp
result = content[i] + '/';
```

This reassigned the entire `result` string during every iteration of the loop, discarding all previously appended path components.

#### Resolution

Modified the reconstruction logic to append each directory instead of replacing the existing string:

```cpp
result = result + content[i] + '/';
```

This preserved all normalized path components and generated the expected canonical path.

---

## Outcome

Successfully implemented the URL Normalizer with support for:

* Scheme normalization
* Hostname normalization
* Fragment removal
* Default HTTP/HTTPS port removal
* Path normalization (`.`, `..`, repeated slashes)
* Canonical URL reconstruction

The implementation now produces the expected normalized URLs and is ready to be integrated with the crawler's frontier for duplicate URL elimination.

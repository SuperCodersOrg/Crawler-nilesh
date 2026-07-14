# Build Log – 14 July 2026 session 1

### Duration: 9:30 AM – 12:30 PM

---

# Goal

Integrate the major crawler components into a complete crawling pipeline. The objective was to make the crawler automatically download webpages, extract hyperlinks, normalize discovered URLs, eliminate unwanted resources, manage the crawling frontier, and recursively continue crawling until the specified depth.

---

# Problem

Although the individual modules (CDP Downloader, HTML Parser, URL Normalizer, and Frontier) were working independently, integrating them exposed several runtime and logical issues.

The crawler frequently terminated due to runtime exceptions, failed to normalize certain URLs correctly, and repeatedly skipped valid pages because of incorrect duplicate detection logic. In addition, HTML parsing produced several invalid URLs and resource links that should not have been crawled.

---

# What I Tried

## Crawler Integration

Implemented the first complete crawler workflow connecting all major components.

The crawling sequence became:

1. Normalize the input URL.
2. Download rendered HTML using Chrome DevTools Protocol (CDP).
3. Parse hyperlinks from the HTML.
4. Normalize every extracted URL.
5. Filter unwanted URLs.
6. Insert valid URLs into the Frontier.
7. Continue crawling recursively until the configured depth.

This marked the first working end-to-end execution of the crawler.

---

## HTML Parser Improvements

Completed the parser implementation and improved extraction of hyperlinks from rendered HTML.

Enhancements included:

- Improved handling of `href` attributes.
- Better extraction of direct `http://` and `https://` links.
- Added additional terminating characters while parsing URLs such as:
  - `;`
  - `)`
  - `'`
  - `"`
- Reduced duplicate and partially extracted links.
- Verified extraction using multiple real websites.

---

## URL Normalizer Enhancements

Extended the URL normalizer to support crawler integration.

Implemented support for:

- Relative URL conversion using the crawler's seed URL.
- Fragment removal.
- Lowercase normalization.
- Path normalization.
- Default HTTP/HTTPS port removal.
- Canonical URL generation.

Also introduced filtering support for:

- Ignored domains
- Ignored file extensions

Both lists are now loaded automatically from configuration files during Normalizer initialization.

---

## Configuration File Support

Created two configuration files:

- `domain.txt`
- `extension.txt`

Implemented a file reader that loads both files during construction of the `Normalizer`.

This makes the ignore list configurable without modifying the source code.

---

## Resource Filtering

Implemented filtering for non-crawlable resources.

Ignored file types include:

- CSS
- JavaScript
- Images
- Fonts
- Videos
- Documents

Also started filtering non-web navigation links such as:

- `mailto:`
- `tel:`
- `javascript:`
- `data:`

These URLs are removed before entering the Frontier.

---

## Frontier Improvements

Updated the Frontier to store additional metadata with every URL.

Each queue entry now contains:

- URL
- Crawl depth
- Last crawl date

Implemented automatic generation of SQL-style date (`YYYY-MM-DD`) whenever a URL is inserted into the Frontier.

---

## Recursive Crawling

Implemented recursive crawling with configurable depth.

The crawler now:

- Downloads a webpage.
- Extracts hyperlinks.
- Inserts newly discovered URLs into the Frontier.
- Retrieves the next URL.
- Continues crawling until the maximum depth is reached.

---

# Problems Encountered

## 1. Class Redefinition Error

### Compiler Error

```
error: redefinition of 'class Frontier'
```

### Root Cause

One of the header files was included multiple times because proper include guards were missing.

### Resolution

Added `#pragma once` to all project headers to prevent duplicate class definitions.

---

## 2. Linker Error (WinMain)

### Compiler Error

```
undefined reference to WinMain
```

### Root Cause

The executable was being linked as a Windows GUI application instead of a console application.

### Resolution

Corrected the build configuration and ensured that a valid `main()` function was linked.

---

## 3. Runtime Exception (`std::out_of_range`)

### Runtime Output

```
basic_string::substr:
__pos > this->size()
```

### Root Cause

`substr()` was being called after the URL had already become empty during normalization.

Cases such as:

- `mailto:`
- `javascript:`
- invalid URLs

were converted into empty strings, but later parsing still attempted to extract the scheme and authority.

### Resolution

Added validation before every `substr()` operation and returned immediately whenever the URL became empty.

---

## 4. Relative URL Handling

Relative URLs such as:

```
#about
/assets/style.css
```

were causing normalization failures.

### Root Cause

The seed URL was not being used correctly while constructing absolute URLs.

### Resolution

Implemented a dedicated `relativeURL()` routine that combines relative paths with the crawler's seed URL before further normalization.

---

## 5. Extension Filtering Failure

Resource URLs containing query parameters were not being ignored.

Example:

```
style.css?v=4
```

The extracted extension became:

```
.css?v=4
```

instead of:

```
.css
```

This prevented successful extension matching.

### Resolution

Identified the need to remove query parameters before comparing file extensions. This remains an area for further refinement.

---

## 6. Duplicate Detection Logic

Initially every discovered URL appeared as already visited.

### Root Cause

The crawler inserted URLs into the `visited` set immediately after pushing them into the Frontier.

As a result, URLs waiting inside the queue were incorrectly treated as already crawled.

### Resolution

Separated the concepts of:

- URLs waiting inside the Frontier.
- URLs that have actually been crawled.

This corrected the recursive crawling behaviour.

---

## 7. Seed URL Normalization

Seed URLs without a trailing slash were treated as invalid.

Example:

```
https://nileshsahu.in
```

### Root Cause

The normalizer assumed that every URL contained a path (`/`).

### Resolution

Updated the normalization logic to correctly handle URLs containing only the authority portion.

---

## 8. Runtime Testing with Real Websites

During testing, several unexpected URL formats were discovered, including:

- `http://`
- `https://`
- Open Graph namespaces
- Escaped Unicode URLs
- Login URLs containing query parameters

These observations highlighted additional edge cases that will require filtering in future iterations.

---

# Outcome

Successfully integrated the major crawler modules into a functional recursive crawling pipeline.

Completed achievements include:

- CDP-based webpage downloading
- Recursive crawler implementation
- HTML link extraction
- URL normalization
- Relative URL handling
- Fragment removal
- Ignore-domain support
- Ignore-extension support
- Configuration file loading
- Frontier metadata support
- Recursive depth control
- Runtime validation for invalid URLs
- Resolution of major compilation, linker, and runtime issues

The crawler is now capable of downloading webpages, extracting valid hyperlinks, normalizing them, filtering unwanted resources, and recursively traversing websites up to the configured crawl depth.

---

# Next Steps

- Separate **Queued URLs** and **Visited URLs** into independent data structures.
- Improve extension detection for URLs containing query parameters.
- Filter invalid namespace URLs such as `http://` and `ogp.me`.
- Decode escaped Unicode sequences inside extracted URLs.
- Store downloaded pages in SQLite through the `PageStorage` module.
- Improve duplicate URL detection across multiple domains.
- Add unit tests for the crawler, URL normalizer, and HTML parser.
# Build Log – 10 July 2026 (Session 2)



## Goal

Complete the implementation of the **HTML Parser**, improve the **URL Normalizer** to support crawler integration, and begin integrating all major crawler components (`Downloader`, `HtmlParser`, `Normalizer`, and `Frontier`) into a single crawling pipeline.

---

## Problem

Although the first version of the HTML Parser was capable of extracting URLs, several edge cases were still present. The extracted links also required additional processing before they could be inserted into the Frontier.

Another challenge was integrating independently developed components into a single crawler workflow. The parser, normalizer, and frontier had been developed separately, but they had not yet been connected into an end-to-end crawling process.

---

## What I Tried

### HTML Parser Completion

Refined the parser implementation by improving both `href` and direct `http/https` URL extraction.

The parser was updated to:

* Handle both quoted and unquoted URL patterns more reliably.
* Correctly advance the parsing index after every extracted URL.
* Reduce incorrect or duplicate URL extraction during sequential parsing.
* Return all discovered links through the internal `DynamicArray`.

Multiple HTML pages were used during testing to verify that links were extracted correctly before moving to the normalization stage.

---

### URL Normalizer Improvements

Updated the URL Normalizer to better support real crawler inputs.

The implementation was enhanced to:

* Process URLs extracted directly from the HTML Parser.
* Normalize relative URLs using the crawler's seed URL.
* Improve fragment removal and canonical URL generation.
* Prepare normalized URLs for duplicate detection before insertion into the Frontier.

These updates ensured that different representations of the same resource are converted into a consistent canonical form.

---

### Crawler Integration

Started integrating all crawler modules into a single execution flow.

The initial crawler pipeline was designed as:

1. Download webpage using the Downloader.
2. Extract links using the HTML Parser.
3. Normalize every extracted URL.
4. Check duplicate URLs through the Frontier.
5. Insert newly discovered URLs into the crawling queue.

This marked the beginning of converting individually tested modules into a complete crawling system.

---

## Problems Encountered

### Header Dependency Issue

While integrating different modules, compilation failed because some header files were being included multiple times through indirect dependencies.

**Root Cause**

The required include guards (`#pragma once`) were missing from one of the project headers, causing the compiler to encounter multiple definitions of the same class.

**Resolution**

Added proper include guards to eliminate duplicate class definitions and restore successful compilation.

---

### Linker Errors During Integration

While combining the crawler modules, linker errors were encountered because some newly implemented source files were not included in the CMake build configuration.

**Resolution**

Updated the build configuration to compile and link all required implementation files correctly.

---

### Parser Integration Testing

While testing the integrated pipeline, several extracted URLs required additional normalization before they could be processed by the crawler. This led to further improvements in the interaction between the HTML Parser and the URL Normalizer.

---

## Outcome

Successfully completed the first working version of the HTML Parser and began integrating it into the crawler pipeline.

Achievements:

* Finalized HTML link extraction logic.
* Improved URL normalization for crawler integration.
* Connected Downloader, HTML Parser, URL Normalizer, and Frontier into the initial crawler workflow.
* Resolved compilation and linker issues encountered during module integration.
* Established the foundation for recursive webpage crawling in future sessions.

---

## Next Steps

* Complete recursive crawling using the Frontier queue.
* Improve handling of relative URLs and resource links.
* Skip non-HTML resources such as images, CSS, and JavaScript files.
* Integrate page storage for saving downloaded HTML.
* Add comprehensive testing for the complete crawling pipeline.

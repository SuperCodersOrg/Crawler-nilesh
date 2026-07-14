# Build Log – 9 July 2026 (Session 1)

**Duration:** 9:00 AM – 12:00 PM
## Goal

Implement the initial version of the **HTML Parser** for the web crawler. The objective was to extract URLs from downloaded HTML content so that newly discovered links could later be normalized and inserted into the Frontier.

---

## Problem

The downloader was successfully fetching webpage content, but the crawler had no mechanism to discover additional URLs present inside the downloaded HTML.

The parser needed to identify links appearing in different formats, including:

- `href="..."`
- `href='...'`
- Direct `http://` and `https://` URLs embedded inside HTML or JavaScript.

A lightweight parser was preferred instead of integrating a third-party HTML parsing library.

---

## What I Tried

### HTML Parser Implementation

- Created a dedicated `HtmlParser` class responsible for scanning downloaded HTML.
- Added an internal `DynamicArray<string>` to store every extracted URL.
- Designed the parser to perform a sequential character-by-character scan over the HTML instead of constructing a DOM tree.

### HTTP URL Extraction

Implemented a parser routine that:

- Searches for occurrences of `http`.
- Continues scanning until a terminating delimiter is found.
- Extracts and stores the complete URL.

Initially handled delimiters such as:

- `'`
- `"`
- `)`

### href Attribute Parsing

Implemented parsing logic for HTML attributes by:

- Detecting the `href` keyword.
- Ignoring spaces around the assignment operator.
- Supporting both single and double quoted attribute values.
- Extracting the URL enclosed inside the quotes.

### Main Parsing Loop

Implemented the parser traversal logic that:

- Iterates through the HTML.
- Detects `href` attributes.
- Detects direct `http` links.
- Calls the corresponding parsing function depending on the matched pattern.

### C++ String Handling

During implementation, explored several C++ string-related concepts including:

- Raw string literals for storing multiline HTML and JavaScript.
- Custom raw string delimiters.
- Character searching using `find()`.
- Handling escaped quotation marks.
- Correct usage of `substr(position, length)`.

---

## Problems Encountered

Several implementation issues were discovered while testing:

- Infinite loop caused by repeatedly parsing the same substring without advancing the current parsing position.
- Incorrect use of `substr()` where the second argument was mistakenly treated as an ending index instead of a length.
- Linker error (`undefined reference`) because `HtmlParser.cpp` was not included during compilation.
- Incorrect inclusion of a `.cpp` file inside the header, producing recursive include errors.
- Difficulty handling quotation characters correctly while parsing HTML attributes.
- Initial parser only handled a limited set of URL termination characters and required additional edge case handling.

---

## Outcome

Successfully completed the first working version of the HTML Parser.

Achievements:

- Implemented extraction of URLs from `href` attributes.
- Implemented extraction of direct `http://` and `https://` links.
- Improved understanding of sequential parsing techniques.
- Identified multiple edge cases that require additional handling before integrating the parser with the crawler pipeline.
- Established the overall parser architecture for future extensions.

---

## Next Steps

- Refactor the parser to avoid repeated `substr()` copies by parsing directly using indices.
- Handle additional URL terminating characters such as whitespace, `<`, `>`, newline, and tabs.
- Add support for extracting URLs from:
  - `src`
  - `action`
  - `iframe`
  - `link`
  - `script`
- Support relative and protocol-relative URLs.
- Integrate the parser with the URL Normalizer and Frontier.
- Write comprehensive unit tests covering valid HTML, malformed HTML, JavaScript-generated links, and edge cases.
# Build Log – 17 July 2026 (Session 2)

## Duration 2:00 pm to 4:00 pm


## Goal
Improve the webpage fetching mechanism by integrating cURL with the existing CDP-based implementation.

## Tasks Completed
- Integrated cURL into the crawler alongside the existing Chrome DevTools Protocol (CDP) implementation.
- Implemented the `isDynamicPage()` function to determine whether a webpage requires JavaScript rendering.
- Added detection for common JavaScript-only placeholder messages.
- Removed `<script>`, `<style>`, and HTML comments before analyzing the page content.
- Calculated the amount of visible text after removing HTML tags.
- Implemented a hybrid page-fetching workflow:
  - Attempt to fetch the page using cURL.
  - If the page is identified as dynamic, automatically fetch the fully rendered HTML using CDP.
  - Otherwise, use the HTML returned by cURL.

## Problems Faced
- Designing a reliable mechanism to distinguish static webpages from JavaScript-rendered webpages.
- Balancing performance by avoiding unnecessary Chrome launches while still supporting dynamic websites.

## What I Learned
- Hybrid webpage fetching strategy using cURL and CDP.
- Techniques for detecting dynamic webpages based on visible content.
- Performance advantages of using cURL for static pages and CDP only when necessary.

## Outcome
Successfully implemented a hybrid page-fetching system that first attempts cURL and automatically falls back to CDP for dynamic webpages, resulting in improved crawler performance and broader website compatibility.
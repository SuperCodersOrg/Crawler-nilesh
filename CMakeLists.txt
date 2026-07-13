cmake_minimum_required(VERSION 3.15)
project(cdp_scraper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ixwebsocket REQUIRED)
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(crawler
    src/Crawler.cpp
    src/Frontier.cpp
    CDP/CDPScraper.cpp
    src/HtmlParser.cpp
    src/Normalizer.cpp
)

target_link_libraries(crawler
    PRIVATE
        ixwebsocket::ixwebsocket
        CURL::libcurl
        nlohmann_json::nlohmann_json
)
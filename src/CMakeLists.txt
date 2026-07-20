cmake_minimum_required(VERSION 3.16)

project(IndexerTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header files
include_directories(../../include)

# MySQL
include_directories("C:/Program Files/MySQL/MySQL Server 8.0/include")
link_directories("C:/Program Files/MySQL/MySQL Server 8.0/lib")

add_executable(IndexerTest
    ../Indexer.cpp
    ../PageStorage.cpp
    ../Normalizer.cpp
    ../HtmlParser.cpp
    ../Frontier.cpp
)

target_link_libraries(IndexerTest mysql)
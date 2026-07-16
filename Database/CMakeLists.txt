cmake_minimum_required(VERSION 3.16)

project(DatabaseTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DatabaseTest
    main.cpp
    ../src/PageStorage.cpp
)

target_include_directories(DatabaseTest PRIVATE
    ../include
    "C:/Program Files/MySQL/MySQL Server 8.0/include"
)

target_link_directories(DatabaseTest PRIVATE
    "C:/Program Files/MySQL/MySQL Server 8.0/lib"
)

target_link_libraries(DatabaseTest PRIVATE
    libmysql)
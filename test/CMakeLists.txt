cmake_minimum_required(VERSION 3.16)

project(DatabaseTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(GTest REQUIRED)

set(MYSQL_ROOT "C:/Program Files/MySQL/MySQL Server 8.0")

add_executable(Tests
    # DatabaseTest.cpp
    PageStorageTests.cpp
    ../src/PageStorage.cpp
     ../Database/Database.cpp
    NormalizerTests.cpp
    ../src/Normalizer.cpp
    QueueTests.cpp
    SetTests.cpp
    

)

target_include_directories(Tests PRIVATE
    ../include
    "${MYSQL_ROOT}/include"
)

target_link_directories(Tests PRIVATE
    "${MYSQL_ROOT}/lib"
)

target_link_libraries(Tests PRIVATE
    GTest::gtest
    GTest::gtest_main
    libmysql
)

include(GoogleTest)
gtest_discover_tests(Tests)
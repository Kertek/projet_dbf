cmake_minimum_required(VERSION 3.6)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests
        MainTests.cpp
        test1.cpp
        )

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests DBFsrc)
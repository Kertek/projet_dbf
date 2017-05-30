cmake_minimum_required(VERSION 3.6)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(projet_dbf_test
        MainTests.cpp
        TestParser.cpp
        TestInjection.cpp
        TestPerformance.cpp TestRequetesMalveillantes.cpp TestRequetesLegitimes.cpp)

target_link_libraries(projet_dbf_test gtest gtest_main)
target_link_libraries(projet_dbf_test DBFsrc)
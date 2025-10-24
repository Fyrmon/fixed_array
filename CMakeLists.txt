cmake_minimum_required(VERSION 3.20)
project(fixed_array LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(arr_lib INTERFACE)
target_include_directories(arr_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/include)

add_executable(fixed_array app/main.cpp)
target_link_libraries(fixed_array PRIVATE arr_lib)

find_package(GTest REQUIRED)
enable_testing()

add_executable(arr_test lib/tests/arr_test.cpp)

target_link_libraries(arr_test PRIVATE
    arr_lib
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(arr_test)
cmake_minimum_required(VERSION 3.20)
project(fixed_array LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(arr src/main.cpp)

target_link_libraries(arr gtest::gtest)
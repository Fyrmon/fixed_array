cmake_minimum_required(VERSION 3.20)
project(fixed_array LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)
add_subdirectory(tests)

add_executable(fixed_array app/main.cpp)
target_link_libraries(fixed_array PRIVATE arr_lib)

find_package(GTest REQUIRED)
enable_testing()

add_executable(arr_test arr_test.cpp)

target_link_libraries(arr_test PRIVATE
    arr_lib
    GTest::gtest
    GTest::gtest_main    
)

include(GoogleTest)
gtest_discover_tests(arr_test)

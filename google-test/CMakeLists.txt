cmake_minimum_required(VERSION 3.16)
project(google_test CXX)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
include(GoogleTest)


find_package(GTest CONFIG REQUIRED)

add_executable(main main.cpp simple-test.cpp)

gtest_add_tests(TARGET main TEST_PREFIX old:)
gtest_discover_tests(main TEST_PREFIX new:)

add_test(NAME main COMMAND main)

target_link_libraries(main PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

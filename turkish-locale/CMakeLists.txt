cmake_minimum_required(VERSION 3.16)

project(turkish-locale CXX)

add_definitions(-D_WIN32_WINNT=0x0601)

set(CMAKE_CXX_STANDARD 17)

add_executable(turkish-locale main.cpp)

target_link_libraries(turkish-locale)

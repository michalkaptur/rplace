cmake_minimum_required(VERSION 3.18)
project(fib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}) # strictly for conan
find_package(GTest REQUIRED)

set(sources
	main.cpp
)

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} GTest::gtest GTest::gtest_main)

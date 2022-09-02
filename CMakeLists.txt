cmake_minimum_required(VERSION 3.18)
project(rplace)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}) # strictly for conan
find_package(GTest REQUIRED)
find_package(Boost REQUIRED system)
find_package(nlohmann_json REQUIRED)
find_package(spdlog REQUIRED)

enable_testing()

set(sources
	main.cpp
)

add_executable(temp_dummy_target ${sources})
target_link_libraries(temp_dummy_target GTest::gtest GTest::gtest_main)

add_subdirectory(src)
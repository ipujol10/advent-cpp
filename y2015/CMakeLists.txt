cmake_minimum_required(VERSION 3.15)

# Variables
set(PROJECT_NAME y2015)

project(${PROJECT_NAME} VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTING "Enable/Disable testing" ON)

add_subdirectory(libs/day1)
if (BUILD_TESTING)
    enable_testing()
    add_test(NAME TestDay1 COMMAND TestDay1)
endif()

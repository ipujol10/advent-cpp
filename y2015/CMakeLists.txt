cmake_minimum_required(VERSION 3.15)

# Variables
set(PROJECT_NAME y2015)

project(${PROJECT_NAME} VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTING "Enable/Disable testing" ON)

add_subdirectory(libs)

add_executable(Day1 src/day1.cpp)
target_link_libraries(Day1 PRIVATE D1_2015)

add_executable(Day2 src/day2.cpp)
target_link_libraries(Day2 PRIVATE D2_2015)

if (BUILD_TESTING)
    enable_testing()
    add_test(NAME TestDay1 COMMAND TestDay1)
    add_test(NAME TestDay2 COMMAND TestDay2)
endif()

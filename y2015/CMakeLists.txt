cmake_minimum_required(VERSION 3.15)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

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

add_executable(Day3 src/day3.cpp)
target_link_libraries(Day3 PRIVATE D3_2015)

add_executable(Day4 src/day4.cpp)
target_link_libraries(Day4 PRIVATE D4_2015)

add_executable(Day5 src/day5.cpp)
target_link_libraries(Day5 PRIVATE D5_2015)

add_executable(Day6 src/day6.cpp)
target_link_libraries(Day6 PRIVATE D6_2015)

add_executable(Day7 src/day7.cpp)
target_link_libraries(Day7 PRIVATE D7_2015)

add_executable(Day8 src/day8.cpp)
target_link_libraries(Day8 PRIVATE D8_2015)

add_executable(Day9 src/day9.cpp)
target_link_libraries(Day9 PRIVATE D9_2015)

add_executable(Day10 src/day10.cpp)
target_link_libraries(Day10 PRIVATE D10_2015)

add_executable(Day11 src/day11.cpp)
target_link_libraries(Day11 PRIVATE D11_2015)

add_executable(Day12 src/day12.cpp)
target_link_libraries(Day12 PRIVATE D12_2015)

add_executable(Day13 src/day13.cpp)
target_link_libraries(Day13 PRIVATE D13_2015)

add_executable(Day14 src/day14.cpp)
target_link_libraries(Day14 PRIVATE D14_2015)

add_executable(Day15 src/day15.cpp)
target_link_libraries(Day15 PRIVATE D15_2015)

add_executable(Day16 src/day16.cpp)
target_link_libraries(Day16 PRIVATE D16_2015)

add_executable(Day17 src/day17.cpp)
target_link_libraries(Day17 PRIVATE D17_2015)

add_executable(Day18 src/day18.cpp)
target_link_libraries(Day18 PRIVATE D18_2015)

add_executable(Day19 src/day19.cpp)
target_link_libraries(Day19 PRIVATE D19_2015)

add_executable(Day20 src/day20.cpp)
target_link_libraries(Day20 PRIVATE D20_2015)

add_executable(Day21 src/day21.cpp)
target_link_libraries(Day21 PRIVATE D21_2015)

add_executable(Day23 src/day23.cpp)
target_link_libraries(Day23 PRIVATE D23_2015)

add_executable(Day22 src/day22.cpp)
target_link_libraries(Day22 PRIVATE D22_2015)

if (BUILD_TESTING)
    enable_testing()
    add_test(NAME TestDay1 COMMAND TestDay1)
    add_test(NAME TestDay2 COMMAND TestDay2)
    add_test(NAME TestDay3 COMMAND TestDay3)
    add_test(NAME TestDay4 COMMAND TestDay4)
    add_test(NAME TestDay5 COMMAND TestDay5)
    add_test(NAME TestDay6 COMMAND TestDay6)
    add_test(NAME TestDay7 COMMAND TestDay7)
    add_test(NAME TestDay8 COMMAND TestDay8)
    add_test(NAME TestDay9 COMMAND TestDay9)
    add_test(NAME TestDay10 COMMAND TestDay10)
    add_test(NAME TestDay11 COMMAND TestDay11)
    add_test(NAME TestDay12 COMMAND TestDay12)
    add_test(NAME TestDay13 COMMAND TestDay13)
    add_test(NAME TestDay14 COMMAND TestDay14)
    add_test(NAME TestDay15 COMMAND TestDay15)
    add_test(NAME TestDay16 COMMAND TestDay16)
    add_test(NAME TestDay17 COMMAND TestDay17)
    add_test(NAME TestDay18 COMMAND TestDay18)
    add_test(NAME TestDay19 COMMAND TestDay19)
    add_test(NAME TestDay20 COMMAND TestDay20)
    add_test(NAME TestDay21 COMMAND TestDay21)
    add_test(NAME TestDay23 COMMAND TestDay23)
    add_test(NAME TestDay22 COMMAND TestDay22)
endif()

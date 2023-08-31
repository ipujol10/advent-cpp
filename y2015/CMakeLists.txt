cmake_minimum_required(VERSION 3.15)

# Variables
set(PROJECT_NAME y2015)

project(${PROJECT_NAME} VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# #########
# # Testing
# #########
# option(BUILD_TESTING "Enable/Disable testing" ON)
# 
# if(BUILD_TESTING)
#     include(FetchContent)
#     FetchContent_Declare(
#         googletest
#         URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
#         )
#     FetchContent_MakeAvailable(googletest)
# endif()

add_subdirectory(libs/day1)

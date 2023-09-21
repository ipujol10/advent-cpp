project(testDay14)

set(TEST_NAME TestDay14)

if (BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        )
    FetchContent_MakeAvailable(googletest)

    add_executable(${TEST_NAME} test.cpp)
    target_link_libraries(${TEST_NAME} gtest_main D14_2015)
endif()

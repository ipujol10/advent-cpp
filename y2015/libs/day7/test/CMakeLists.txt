project(testDay7)

set(TEST_NAME TestDay7)

if (BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        )
    FetchContent_MakeAvailable(googletest)

    #add_executable(${TEST_NAME} test.cpp test_improved.cpp test_virtual.cpp)
    add_executable(${TEST_NAME} test_virtual.cpp)
    target_link_libraries(${TEST_NAME} gtest_main D7_2015)
endif()

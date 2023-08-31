project(testDay1)

set(TEST_NAME TestDay1)

#########
# Testing
#########
if (BUILD_TESTING)
    if(BUILD_TESTING)
        include(FetchContent)
        FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
            )
        FetchContent_MakeAvailable(googletest)
    endif()

    add_executable(${TEST_NAME} test.cpp)
    target_link_libraries(${TEST_NAME} gtest_main D1_2015)
endif()

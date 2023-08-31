project(testDay1)

#########
# Testing
#########
option(BUILD_TESTING "Enable/Disable testing" ON)

if(BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        )
    FetchContent_MakeAvailable(googletest)
endif()

enable_testing()

add_executable(Test test.cpp)
target_link_libraries(Test gtest_main D1_2015)

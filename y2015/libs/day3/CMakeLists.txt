project(Day3_2015)

set(LIBRARY_NAME D3_2015)

add_library(${LIBRARY_NAME} STATIC
    include/${LIBRARY_NAME}/day3.hpp
    src/day3.cpp
    )

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
    )

target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    )

target_link_libraries(${LIBRARY_NAME} gtest_main)

add_subdirectory(test)

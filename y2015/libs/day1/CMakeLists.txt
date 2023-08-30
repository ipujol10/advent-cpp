project(Day1_2015)

set(LIBRARY_NAME D1_2015)

add_library(${LIBRARY_NAME} STATIC
    include/day1.hpp
    src/day1.cpp
    )

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
    )

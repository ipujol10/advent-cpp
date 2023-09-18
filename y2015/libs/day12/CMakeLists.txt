project(Day12_2015)

set(LIBRARY_NAME D12_2015)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_library(${LIBRARY_NAME} STATIC
    include/${LIBRARY_NAME}/day12.hpp
    src/day12.cpp
    )

target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
    )

target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    )

target_link_libraries(${LIBRARY_NAME} PRIVATE nlohmann_json::nlohmann_json)

add_subdirectory(test)

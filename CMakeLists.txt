cmake_minimum_required(VERSION 3.0.0)
project(FSTAB-Manager VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(cmake_libs/simple_table)
add_subdirectory(cmake_libs/term_color)
add_subdirectory(cmake_libs/escape_codes)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)
link_directories(${CMAKE_BINARY_DIR}/lib)

add_executable(FSTAB-Manager
    src/main.cpp
    cmake_libs/simple_table/include/table.hpp
    cmake_libs/term_color/include/color.hpp
    cmake_libs/escape_codes/include/ansi_codes.hpp
)

target_link_libraries(FSTAB-Manager PUBLIC SIMPLE-TABLE-STATIC)
target_link_libraries(FSTAB-Manager PUBLIC TERM-COLOR-STATIC)
target_link_libraries(FSTAB-Manager PUBLIC ANSI-ESCAPE-CODES-STATIC)

target_include_directories(FSTAB-Manager PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/cmake_libs/simple_table"
    "${PROJECT_SOURCE_DIR}/cmake_libs/simple_table/include"
    "${PROJECT_SOURCE_DIR}/cmake_libs/term_color"
    "${PROJECT_SOURCE_DIR}/cmake_libs/term_color/include"
    "${PROJECT_SOURCE_DIR}/cmake_libs/escape_codes"
    "${PROJECT_SOURCE_DIR}/cmake_libs/escape_codes/include"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

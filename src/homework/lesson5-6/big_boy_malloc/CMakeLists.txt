cmake_minimum_required(VERSION 3.21)
project(BigBoyMalloc C)

set(PROJECT_AUTHOR "Nikita Djandjgava")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)
enable_testing()

add_executable(malloc_main malloc_main.c)
add_library(library2 library2.c library2.h)
target_link_libraries(malloc_main PRIVATE library2)
add_subdirectory(testing)
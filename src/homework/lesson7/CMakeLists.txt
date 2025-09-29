cmake_minimum_required(VERSION 3.21)
project(Rectangle C)

set(PROJECT_AUTHOR "Nikita Djandjgava")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)
enable_testing()

add_executable(struct_main struct_main.c)
add_library(rectangle rectangle.c rectangle.h)
target_link_libraries(struct_main PRIVATE rectangle)
add_subdirectory(testing)
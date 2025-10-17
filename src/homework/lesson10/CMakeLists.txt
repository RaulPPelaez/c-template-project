cmake_minimum_required(VERSION 3.21)
project(Rectangle C)

set(PROJECT_AUTHOR "Nikita Djandjgava")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)
enable_testing()

add_library(welcome src/welcome.c)
target_include_directories(welcome PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )

add_executable(lesson10_main ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
target_link_libraries(lesson10_main PRIVATE welcome)
set_target_properties(lesson10_main PROPERTIES OUTPUT_NAME main)

add_subdirectory(testing)
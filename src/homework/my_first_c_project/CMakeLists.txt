# project/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(my_first_c_project C)
set(CMAKE_C_STANDARD 23)

# Force executables to land in build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)

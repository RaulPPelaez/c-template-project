cmake_minimum_required(VERSION 3.21) # Always required in a CMakeLists
project(lesson4 C) # Name of the project and main language
# Makes sources in this folder available for all sources to "include"
include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src) # Delegate to src/CMakeLists.txt
enable_testing() # Enable the testing integration
add_subdirectory(tests) # Delegate to tests/CMakeLists.txt
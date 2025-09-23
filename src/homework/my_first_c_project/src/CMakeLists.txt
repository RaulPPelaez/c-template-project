# Build the library from library.c
add_library(my_library library.c)
target_include_directories(my_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Build the executable and link the library
add_executable(my_app main.c)
target_link_libraries(my_app PRIVATE my_library)
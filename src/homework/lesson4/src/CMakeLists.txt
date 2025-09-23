add_library(name_length name_length.c) # Create a library from the source file
add_executable(main main.c) # Create an executable from the source file
target_link_libraries(main name_length) # Link the executable to the library
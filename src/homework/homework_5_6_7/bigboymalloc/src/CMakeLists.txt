add_library(functions functions.c) # Create a library from the source file
add_executable(main main.c) # Create an executable from the source file
target_link_libraries(main functions) # Link the executable to the library
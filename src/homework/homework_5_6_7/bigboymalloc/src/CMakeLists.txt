add_library(functions functions.c)
add_executable(bigboymalloc main.c)
target_link_libraries(bigboymalloc functions)
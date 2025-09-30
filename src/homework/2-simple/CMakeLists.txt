add_library(my_library library.c library.h)
add_executable(homework2 main.c)
target_link_libraries(homework2 PRIVATE my_library)

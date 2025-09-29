add_library(rectangle rectangle.c)
add_executable(main main.c)
target_link_libraries(main rectangle)
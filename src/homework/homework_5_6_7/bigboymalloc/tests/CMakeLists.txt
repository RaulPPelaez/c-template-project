add_executable(test_malloc test_malloc.c)
target_link_libraries(test_malloc functions)
target_include_directories(test_malloc PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/third_party)
add_test(NAME test_malloc COMMAND test_malloc)

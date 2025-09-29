include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party)

add_executable(test_rectangle test_rectangle.c)
target_link_libraries(test_rectangle rectangle)

add_test(NAME test_rectangle COMMAND test_rectangle)
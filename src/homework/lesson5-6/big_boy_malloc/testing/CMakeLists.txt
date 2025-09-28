# Create an executable from the source file
add_executable(test_malloc test_malloc.c)
# Link the executable to the library
target_link_libraries(test_malloc library2)
# Make sure the test can find the headers
target_include_directories(test_malloc PRIVATE ${PROJECT_SOURCE_DIR}/third_party ${PROJECT_SOURCE_DIR})
# Register the test with CTest
add_test(NAME test_malloc COMMAND test_malloc)
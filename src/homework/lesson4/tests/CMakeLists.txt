# Create an executable from the source file
add_executable(test_name_length test_name_length.c)
# Link the executable to the library
target_link_libraries(test_name_length name_length)
# Make sure the test can find the headers
target_include_directories(test_name_length PRIVATE ${PROJECT_SOURCE_DIR}/third_party)
# Register the test with CTest
add_test(NAME test_name_length COMMAND test_name_length)
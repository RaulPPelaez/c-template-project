# Create an executable from the source file
add_executable(test_rectangle test_rectangle.c)
# Link the executable to the library
target_link_libraries(test_rectangle rectangle)
# Make sure the test can find the headers
target_include_directories(test_rectangle PRIVATE ${PROJECT_SOURCE_DIR}/third_party ${PROJECT_SOURCE_DIR})
# Register the test with CTest
add_test(NAME test_rectangle COMMAND test_rectangle)
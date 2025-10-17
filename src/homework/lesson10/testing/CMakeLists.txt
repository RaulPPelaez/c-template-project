# Create an executable from the source file
add_executable(test_welcome test_welcome.c)
# Link the executable to the library
target_link_libraries(test_welcome welcome)
# Make sure the test can find the headers
target_include_directories(test_welcome PRIVATE ${PROJECT_SOURCE_DIR}/third_party ${PROJECT_SOURCE_DIR}/include)
# Register the test with CTest
add_test(NAME test_welcome COMMAND test_welcome)
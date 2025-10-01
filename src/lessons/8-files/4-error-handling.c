#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  // Try to open a non-existent file for reading
  FILE *file = fopen("non_existent_file.txt", "r");
  if (!file) {
    fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }
  // Close the file (this line will not be reached in this example)
  fclose(file);
  return EXIT_SUCCESS;
}
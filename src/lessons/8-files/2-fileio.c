#include <stdio.h>
int main() {
  FILE *f = fopen("tempfile.txt", "w");
  if (!f) {
    perror("fopen");
    return 1;
  }
  fprintf(f, "Hello File I/O!\n");
  fclose(f);
  return 0;
}
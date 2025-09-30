#include <stdio.h>

int main() {
  int x = 5;
  void *ptr = &x;            // Cast int* to void*
  int *int_ptr = (int *)ptr; // Cast void* back to int*
  printf("Value of x: %d\n", *int_ptr);
  return 0;
}

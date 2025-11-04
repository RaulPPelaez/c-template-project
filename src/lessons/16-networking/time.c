#include <stdio.h>
#include <time.h>

const char *get_local_time() {
  time_t timer;
  time(&timer);
  return ctime(&timer);
}

int main() {
  printf("Local time is: %s", get_local_time());
  return 0;
}
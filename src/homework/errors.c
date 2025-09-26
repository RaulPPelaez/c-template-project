# include <stdio.h>
# include <stdlib.h>
#include <string.h>
# include <errno.h>

static int had_error = 0;            

void goodbye_message() {
printf("Last errno call:\n");
fprintf(stderr, "Error code: %d (%s)\n", errno, strerror(errno));
if(had_error){
    fprintf(stderr, "------- Program ended due to an error -------\n");
}
else{
    printf("------- Thanks for using this program -------\n");}
}

void print_array(int *arr, int size) {
if (arr == NULL) {
        had_error = 1;
        fprintf(stderr, "Error: print_array: null pointer\n");
        return; 
    }
    if (size <= 0) {
        had_error = 1;
        fprintf(stderr, "Error: print_array: size must be > 0\n");
        return; 
    }
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}


void vectorized_divide(int *a, int *b, int *result, int size) {
    if (size <= 0) {
        had_error = 1;
        fprintf(stderr, "Error: vectorized_array: size must be > 0\n");
        return; 
    }
      if (a==NULL || b==NULL || result==NULL) {
        had_error = 1;
        fprintf(stderr, "Error: vectorized_array: array pointer is null\n");
        return; 
    }
for (int i = 0; i < size; i++) {
if(b[i]==0){
    had_error=1;
    fprintf(stderr, "Error: Cannot divide by 0\n");
    return;
}
result[i] = a[i] / b[i];
}
}


int main() {
atexit(goodbye_message);
int numbers[5] = {1, 2, 3, 4, 20};
int divisors[5] = {0, 1, 2, 3, 4};
int results[5] = {0};
vectorized_divide(numbers, divisors, results, 5);
if (had_error) {
    return EXIT_FAILURE;
}
print_array(results, sizeof(results) / sizeof(results[0]));
if (had_error) {
    return EXIT_FAILURE;
}
return EXIT_SUCCESS;
}
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# define MAX_SIZE 100
// First function
void print_array(int *arr, int size) {
    assert(arr != NULL);
    assert(size > 0);
    assert(size < MAX_SIZE);
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Second function
static_assert(sizeof(int) == 4, "int must be 4 bytes");
void vectorized_divide(int *a, int *b, int *result, int size) {
for (int i = 0; i < size; i++) {
    if (b[i] == 0) {
        fprintf(stderr, "Error: Division by zero at index %d\n", i);
        exit(EXIT_FAILURE);
}
result[i] = a[i] / b[i];
}
}
int main() {
int numbers[5] = {1, 2, 3, 4, 20};
int divisors[5] = {0, 1, 2, 3, 4};
int results[5] = {0};
vectorized_divide(numbers, divisors, results, 5);
print_array(results, sizeof(results) / sizeof(results[0]));
return EXIT_SUCCESS;
}

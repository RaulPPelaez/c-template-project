#include "library2.h"

int main() {
    int *arr = NULL;
    size_t len = 0;

    printf("Enter integers (negative integer to stop):\n");
    if (read_input(&arr, &len) != 0) {
        fprintf(stderr, "Error reading input or memory allocation failed.\n");
        free(arr);
        return 1;
    }
    if (operations(arr, len) != 0) {
        free(arr);
        return 1;
    }
    free(arr);
    return 0;
}
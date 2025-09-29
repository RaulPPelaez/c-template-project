#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int append_one(int **arr, size_t *len, int value) {
    size_t new_len = *len + 1;
    *arr = realloc(*arr, new_len * sizeof(int));
    if (*arr == NULL) {
        return -1; // Memory allocation failed
    }
    (*arr)[*len] = value;
    *len = new_len;
    return 0; // Success
}

int read_input(int **arr, size_t *len) {
    int value=0;
    while (value >= 0) {
        scanf("%d", &value);
        if (value < 0) {
            break;
        }
        if (append_one(arr, len, value) != 0) {
            return -1; // Memory allocation failed
        }
    }
    return 0; // Success
}

int operations(int *arr, size_t len) {
    if (len == 0) {
        printf("Array is empty.\n");
        return -1;
    }
    int sum = 0;
    printf("Array elements: ");
    for (size_t i = 0; i < len; i++) {
        sum += arr[i];
        printf("%d ", arr[i]);
    }
    double average = (double)sum / len;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    return 0; // Success
}

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
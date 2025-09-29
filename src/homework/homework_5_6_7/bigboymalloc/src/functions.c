#include <stdio.h>
#include <stdlib.h>

int *read_input(int *count) {
    int capacity = 2;
    *count = 0;
    int *arr = malloc(capacity * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }

    while (1) {
        int num;
        printf("Enter a number (negative to stop): ");
        if (scanf("%d", &num) != 1) {
            fprintf(stderr, "Error: invalid input (not an integer)\n");
            free(arr);
            exit(1);
        }

        if (num < 0) {
            break;
        }

        if (*count == capacity) {
            capacity *= 2;
            int *tmp = realloc(arr, capacity * sizeof(int));
            if (tmp == NULL) {
                fprintf(stderr, "Error: realloc failed\n");
                free(arr);
                exit(1);
            }
            arr = tmp;
        }

        arr[*count] = num;
        (*count)++;
    }

    return arr;
}

void print_array(int* arr, int count) {
    if (arr == NULL) {
        fprintf(stderr, "Error: NULL array passed to print_array\n");
        return;
    }

    printf("Array: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compute_sum(int* arr, int count) {
    if (arr == NULL) {
        fprintf(stderr, "Error: NULL array passed to compute_sum\n");
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    return sum;
}

double compute_average(int sum, int count) {
    if (count == 0) {
        fprintf(stderr, "Warning: trying to compute average of 0 numbers\n");
        return 0.0;
    }
    return (double)sum / count;
}

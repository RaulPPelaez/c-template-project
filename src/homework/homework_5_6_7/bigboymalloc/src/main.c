#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main() {
    int count;
    int *arr = read_input(&count);
    
    print_array(arr, count);
    
    int sum = compute_sum(arr, count);
    double average = compute_average(sum, count);
    
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    
    free(arr); 
    return 0;
}
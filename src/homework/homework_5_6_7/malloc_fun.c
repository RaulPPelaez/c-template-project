#include <stdio.h>
#include <stdlib.h>
// Function prototypes (apparently code wont run without it)
int* read_input(int *count);
void print_array(int* arr, int count);
int compute_sum(int* arr, int count);
double compute_average(int sum, int count);

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

// function to create an array of n integers inputed by the user
int *read_input(int *count) {
  int capacity = 2;
  *count = 0;
  int *arr = malloc(capacity * sizeof(int));

  while (1) {
    int num;
    printf("Enter a number (negative to stop): ");
    scanf("%d", &num);

    if (num < 0) {
      break; 
    }

    // resizing array 
    if (*count == capacity) {
      capacity *= 2; 
      arr = realloc(arr, capacity * sizeof(int));
    }

    arr[*count] = num; 
    (*count)++;       
  }

  return arr;
}
// Print function 
void print_array(int* arr, int count) {
    printf("Array: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//The sum function
int compute_sum(int* arr, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    return sum;
}
// The average function 
double compute_average(int sum, int count) {
    if (count == 0) return 0; 
    return (double)sum / count;
}
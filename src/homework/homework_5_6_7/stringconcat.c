#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to concatenate two strings

char *string_concat(char *str1, char *str2, char *result) {
  strcpy(result, str1);
  strcat(result, str2);
  return result;
}

// main
int main() {
  char str1[100];
  char str2[100];
  char result[200]; 
  
  printf("Enter the first string: ");
  scanf("%s", str1);

  printf("Enter the second string: ");
  scanf("%s", str2);

  string_concat(str1, str2, result);

  printf("Concatenated string: %s\n", result);

  return 0;
}
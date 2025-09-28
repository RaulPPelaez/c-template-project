#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* concat(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = (char*)malloc(len1 + len2 + 1); // +1 for the null terminator
    if (result == NULL) {
        return NULL; // Handle memory allocation failure
    }
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main() {
    const char* string1 = "Hello, ";
    const char* string2 = "my name is Nikita!";
    char* concatenated = concat(string1, string2);
    if (concatenated != NULL) {
        printf("Concatenated String: %s\n", concatenated);
        free(concatenated); // Free the allocated memory
    } else {
        printf("Memory allocation failed\n");
    }
    return 0;
}
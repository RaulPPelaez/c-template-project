#include <stdio.h>

// "Everything" is a file
int main(){
    FILE* f = stdout;
    // stderr for errors
    // stdin for input (writting in the terminal)
    fprintf(f, "Hello World!\n");
    return 0;
}
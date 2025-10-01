#include<stdio.h>

int main(int argc, char *argv[]){
    printf("Program name: %s\n", argv[0]);
    if(argc > 1){
        for(int i = 1; i < argc; i++){
            printf("Argument %d: %s\n", i, argv[i]);
        }
    } else {
        printf("No additional arguments were passed.\n");
    }
    return 0;
}
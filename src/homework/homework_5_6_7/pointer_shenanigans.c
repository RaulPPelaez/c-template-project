#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 7;
    int y = 23;
    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);
    return 0;
}

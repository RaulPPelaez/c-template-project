#include "rectangle.h"

int area(Rectangle r){
    if (r.length <= 0 || r.width <= 0) {
        printf("Invalid rectangle dimensions\n");
        return -1;
    }
    return r.length * r.width;
}

void grow(Rectangle *r, int dw, int dl){
    if (dw == 0 || dl == 0) {
        printf("Cannot grow at a factor of 0\n");
        return;
    }
    if (dw < 0 || dl < 0) {
        printf("Cannot grow at a negative factor\n");
        return;
    }
    else{
        (*r).length *= dl;
        (*r).width *= dw;
    }
}

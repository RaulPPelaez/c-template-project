#include "rectangle.h"

int main(){
    Rectangle r = {5, 10};
    printf("Area: %d\n", area(r));
    grow(&r, 2, 3);
    printf("New Area: %d\n", area(r));
    return 0;
}
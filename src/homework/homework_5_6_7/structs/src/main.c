#include <stdio.h>
#include "rectangle.h"

int main() {
    Rectangle rect = {5, 10};

    printf("Initial area: %d\n", area(rect));

    grow(&rect, 2, 3);

    printf("New width: %d, New height: %d\n", rect.width, rect.height);
    printf("New area: %d\n", area(rect));

    return 0;
}
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Rectangle {
    int width;
    int length;
} Rectangle;

typedef struct Rectangle Rectangle;

int area(Rectangle r);

void grow(Rectangle *r, int dw, int dl);

#endif // RECTANGLE_H
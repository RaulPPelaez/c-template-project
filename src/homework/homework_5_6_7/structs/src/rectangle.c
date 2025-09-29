#include "rectangle.h"

int area(Rectangle r) {
    return r.width * r.height;
}

void grow(Rectangle *r, int dw, int dh) {
    r->width += dw;
    r->height += dh;
}

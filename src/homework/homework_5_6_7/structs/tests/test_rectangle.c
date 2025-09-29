#include "utest.h"
#include "rectangle.h"

UTEST(rectangle, area) {
    Rectangle r = {3, 4};
    EXPECT_EQ(area(r), 12);
}

UTEST(rectangle, grow) {
    Rectangle r = {2, 2};
    grow(&r, 1, 2);
    EXPECT_EQ(r.width, 3);
    EXPECT_EQ(r.height, 4);
}

UTEST_MAIN();

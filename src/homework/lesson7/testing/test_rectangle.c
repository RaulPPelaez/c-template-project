# include "utest.h"
# include "rectangle.h"
UTEST(rectangle, basic_tests) {
	Rectangle r = (Rectangle){3, 3};
	ASSERT_EQ(area(r), 9);
    Rectangle r2 = (Rectangle){-5, 0};
    ASSERT_EQ(area(r2), -1);
}
UTEST(rectangle, advanced_tests) {
    Rectangle r = (Rectangle){3, 3};
    grow(&r, 2, 3);
    ASSERT_EQ(area(r), 54);
    grow(&r, -1, -1);
    ASSERT_EQ(area(r), 54);
    grow(&r, 0, 10);
    ASSERT_EQ(area(r), 54);
}
UTEST_MAIN()
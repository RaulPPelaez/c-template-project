# include "utest.h"
# include "library2.h"
UTEST(LIBRARY2_H, append_three_values) {
  int *arr = NULL;
  size_t len = 0;

  ASSERT_EQ(0, append_one(&arr, &len, 10));
  ASSERT_EQ(1u, len);
  ASSERT_NE(NULL, arr);
  ASSERT_EQ(10, arr[0]);

  ASSERT_EQ(0, append_one(&arr, &len, 20));
  ASSERT_EQ(2u, len);
  ASSERT_EQ(20, arr[1]);

  ASSERT_EQ(0, append_one(&arr, &len, 30));
  ASSERT_EQ(3u, len);
  ASSERT_EQ(30, arr[2]);

  free(arr);
}

UTEST(LIBRARY2_H, operations_empty_array) {
  int *arr = NULL;
  size_t len = 0;
  // Expect your operations() to report empty and return -1
  ASSERT_EQ(-1, operations(arr, len));
}

UTEST(LIBRARY2_H, operations_nonempty) {
  int *arr = NULL;
  size_t len = 0;

  // Build a small array: [1, 2, 3]
  ASSERT_EQ(0, append_one(&arr, &len, 1));
  ASSERT_EQ(0, append_one(&arr, &len, 2));
  ASSERT_EQ(0, append_one(&arr, &len, 3));
  ASSERT_EQ(3u, len);

  // operations() prints elements + sum + average; we assert the return code
  ASSERT_EQ(0, operations(arr, len));

  free(arr);
}
UTEST_MAIN()
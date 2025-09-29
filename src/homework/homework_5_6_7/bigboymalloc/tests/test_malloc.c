#include "functions.h"
#include "utest.h"

UTEST(mallocfun, sum_of_array) {
    int arr[3] = {1, 2, 3};
    int sum = compute_sum(arr, 3);
    ASSERT_EQ(sum, 6);
}

UTEST(mallocfun, average_of_array) {
    int arr[3] = {2, 4, 6};
    int sum = compute_sum(arr, 3);
    double avg = compute_average(sum, 3);
    ASSERT_EQ(avg, 4); 
}

UTEST_MAIN();

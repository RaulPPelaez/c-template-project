# include "utest.h"
# include "welcome.h"
#include <string.h>

UTEST(welcome, basic_tests){
    const char* msg = get_welcome_message();
    ASSERT_TRUE(strcmp(msg, "Hello, World!\n") == 0);
}
UTEST_MAIN()
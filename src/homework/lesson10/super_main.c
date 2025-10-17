# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "super_assert.h" // This is where you must define the macro

int main(){
int x = 5;
super_assert(x == 5, "x should be 5");
super_assert(x != 5, "x should not be 5");
return 0;
}
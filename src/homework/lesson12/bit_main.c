#include <stdio.h>

#include <stdio.h>

void print_bits32(int x)
{
    unsigned int mask = 1u << 31;  // start with the most-significant bit

    for (int i = 0; i < 32; ++i) {
        printf("%c",((x & mask) ? '1' : '0'));
        //this works even for two's complement because the program automatically 
        //makes them like that in bits so you just do the same thing of checking bits one by one
        mask >>= 1;
    }
    printf("\n");
}

int main()
{
    print_bits32(0xDEADBEEF);
    print_bits32(-42);
    print_bits32(3);
    return 0;
}
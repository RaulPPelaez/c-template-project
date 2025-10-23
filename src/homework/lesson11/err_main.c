#include <stdio.h>
#include <errno.h>

typedef enum{
    MACCES,
    MNOMEM,
    MINVAL
} ErrorCode;

const char* getErrorMessage(ErrorCode x){
    const char* r;
    switch(x){
        case 0: {
            r = "Error: Permission Denied";
            break;
        }
        case 1: {
            r = "Error: Out of memory";
            break;
        }
        case 2:{
             r = "Error: Invalid Argument";
             break;
        }
    }
    return r;
}

int main(){
    ErrorCode n = MNOMEM;
    const char* bla;
    bla = getErrorMessage(n);
    printf("%s\n",bla);

    return 0;
}

/*
Question answers:
1)  Becuase it takes an ErrorCode as the input and since it is an enum, all options are accounted for.
    There can be no other errror codes
2)  As quoted from the documentation - "The returned string must not be modified by the program, 
    but may be overwritten by a subsequent call to the strerror function. strerror is not required to be thread-safe".
    That seems to address both questions to whyt the pointer is not derefrenced and why modifying it would be unwise.
*/
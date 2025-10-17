#include "welcome.h"

const char* get_welcome_message(){
    #if (LANGUAGE == EN)
    return HELLO_EN;
    #elif (LANGUAGE == ES)
    return HELLO_ES;
    #else
    return ERROR;
    #endif
}
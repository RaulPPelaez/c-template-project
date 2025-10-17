# pragma once
#include <stdio.h>

#ifndef LANGUAGE
#define LANGUAGE 0
#endif
// defining languages as values for the if statements to be able to process them
#define EN 0
#define ES 1

#define ERROR "Error: Failed to define language"
#define HELLO_EN "Hello, World!\n"
#define HELLO_ES "Hola, Mundo!\n"

const char* get_welcome_message();
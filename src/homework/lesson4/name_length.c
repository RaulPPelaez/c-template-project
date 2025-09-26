#include "name_length.h"

int name_length(const char* name) {
    int i = 0;     
    int length = 0; 

    while (name[i] != '\0') {
        if (name[i] != ' ')
            length++;
        i++;
    }
    return length;
}

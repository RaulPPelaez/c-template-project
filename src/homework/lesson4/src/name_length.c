# include "name_length.h"
int name_length(const char* name) {
    int counter = 0;
    int i = 0;
    while (name[i]!= '\0') {
        if (name[i] != ' '){
            counter ++;
        }
        i++;
    }

    return counter;
}
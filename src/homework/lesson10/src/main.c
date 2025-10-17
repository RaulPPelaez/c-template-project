#include "welcome.h"

int main() {

    const char* msg = (const char*)get_welcome_message();
    printf("%s", msg);
    
    return 0;
}

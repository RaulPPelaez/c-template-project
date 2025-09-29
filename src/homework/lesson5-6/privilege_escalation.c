# include <stdio.h>
# include <string.h>
void root_privileged_print(const char* message, long user)
{
    if (user==0xbada55)
    {
        printf("Root says: %s\n", message);
    }
    if(user == 0xdeadbeef)
    {
        printf("Users do not have access to this function\n");
    }
}

void injection()
{
    root_privileged_print("ALL YOUR BASE ARE BELONG TO US", 0x0bada55); 
    /*you said think outside of the box so i tried my best to.
    Also, stack smashing didn't really work, at least for my vscode*/
}

int main(){
long user = 0xdeadbeef;
injection();
root_privileged_print("ALL YOUR BASE ARE BELONG TO US", user);
return 0;
}

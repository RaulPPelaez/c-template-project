#include<stdio.h>

typedef struct {
    int a;
    double b;
    char c;
    } repro_t;

//well this is a structure that stores three different types of variables

typedef struct {
    char *name;
    int offset;
    } netField_t;

//like the previous one, random variables, but one of them is a pointer this time

# define NETF(x) #x,(int)&(((repro_t*)0)->x)
//no clue, I do not understand how there can be a logical operation between a data type (int) and a structure??

    netField_t reproFields[] =
    {
        { NETF(a) },
        { NETF(b) },
        { NETF(c) },
    };

//from context, i'm guessing somehow NETF through that mystical pice of code gained access to repo_t's variables 
//and could access them as the netfield struct

int main() {
    for (int i = 0; i < 3; i++) 
    {
        printf("Field: %s, Offset: %d\n",
        reproFields[i].name, reproFields[i].offset);
        //I would guess this prints the padding based on the output I saw. but how or why is beyond me a bit
    }

return 0;
}
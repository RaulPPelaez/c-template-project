#include <stdio.h>
#include <string.h>

int create_example_file(char* name){
    FILE *f = fopen("tempfile.txt", "w+");
    if(!f){
        perror("fopen");
        return 1;
    }
    fprintf(f, "Hello File I/O!\n");
    fclose(f);
    return 0;
}

int main(){
    create_example_file("tempfile.txt");
    FILE *f = fopen("tempfile.txt", "r");
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), f)){
        printf("Read the following %lu characters: %s", strlen(buffer), buffer);
    }
    // Check that file ended
    if(feof(f)){
        fprintf(stdout, "Reached end of file\n");
    }
    fclose(f);
    return 0;
}
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
#include <errno.h>





void readBook(const char* fileName, char** contents){//I hate this double pointer with a passion. I have spent 2 HOURS debugging. 2 HOURS!!!
    FILE *file = fopen(fileName, "r");
    if (file==NULL){
        printf("Error opening file: %s\n", strerror(errno));
        return;
    }
    int c = fgetc(file);
    int Just_put_a_space = 1;
    *contents = malloc(1);
    if (*contents == NULL){
        printf("Memory allocation error: %s\n", strerror(errno));
        fclose(file);
        return;
    }
    int len = 0;
    (*contents)[0] = '\0';
    while (c != EOF){
        if (isalpha((unsigned char)c)){
            char *tmp = realloc(*contents, len + 2);
            if (tmp == NULL){
                printf("Memory allocation error: %s\n", strerror(errno));
                fclose(file);
                return;
        }
            *contents = tmp;
            (*contents)[len] = c;
            (*contents)[len + 1] = '\0';
            Just_put_a_space = 0;
            len++;
        } else if (!Just_put_a_space){
            char *tmp = realloc(*contents, len + 2);
            if (tmp == NULL){
                printf("Memory allocation error: %s\n", strerror(errno));
                fclose(file);
                return;
            }
            *contents = tmp;
            (*contents)[len] = ' ';
            (*contents)[len + 1] = '\0';
            Just_put_a_space = 1;
            len++;
        }
        c = fgetc(file);
    }
    for (int i = 0; i < len; i++){
        (*contents)[i] = (char)tolower((unsigned char)(*contents)[i]);// bane of my existence
    }
    fclose(file);
    return;
}
//comparison function for qsort
int comp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}


/**
* @brief Counts the frequency of each word in the book.
* The caller is responsible for freeing the allocated memory.
* @param book A continuous array of characters containing the book.
* @param words A pointer to an array of strings that will be allocated
by the function and contain the unique words in the book.
* @param frequencies A pointer to an array of integers that will be allocated
by the function and contain the frequency of each word in the book.
* @param nWords A pointer to an integer that will be
set to the number of unique words in the book.
**/
void countWords(const char* book, char*** words, int** frequencies, int* nWords){
    size_t i=0;
    size_t memory_cap = 1024;
    *words = malloc(memory_cap * sizeof(char*));
    //to not mess with the original contents string
    char *copy = strdup(book); // makes a writable copy according to chat
    if (!copy) { 
        printf("Memory allocation error: %s\n", strerror(errno));
        return;
    }
    if (*words == NULL){
        printf("Memory allocation error: %s\n", strerror(errno));
        return;
    }
    char *token = strtok(copy, " ");
    while (token){
        if (i + 1 >= memory_cap) {
            memory_cap *= 2;
            char **tmp = realloc(*words, memory_cap * sizeof(char*));
            if (!tmp) {
                printf("Memory allocation error: %s\n", strerror(errno));
                return;
            }
            *words = tmp;
        }
        (*words)[i++]=strdup(token);//to be able to free the copy afterwards
        token = strtok(NULL, " ");
    }
    int n = 0;
    *frequencies = calloc(i, sizeof(**frequencies));  // to be able to increment right out of the gate, cause I'm cool like that
        if (*frequencies == NULL){
        printf("Memory allocation error: %s\n", strerror(errno));
        return;
    }
    qsort(*words, i, sizeof(const char*), comp);

    size_t write = 0;
    size_t read  = 0;

    while (read < i) {
        size_t run = 1;
        while (read + run < i &&
           strcmp((*words)[read], (*words)[read + run]) == 0) {
            run++;
     }   
        (*words)[write] = (*words)[read];//will jump over all of the already used words
        (*frequencies)[write] = (int)run;//same here, kinda
        write++;
        read += run;
    }
    *nWords = (int)write;  
    printf("Number of different words is : %d\n", *nWords);
    free(copy); 
    /**int same_word = 0;
    for ( int j=0;j<i-1;j++){
        if (strcmp((*words)[j], (*words)[j+1]) == 0){
            (*frequencies)[n]++;
            same_word=1;
        }
        else{
            same_word=0;
            (*nWords)++;
            n++;
        }
    }**/
}

static void write_rank_freq_simple(const char *path, char **words, int *freq, int n)
{
    // descending selection sort by freq
    for (int i = 0; i < n - 1; i++) {
        int best = i;
        for (int j = i + 1; j < n; j++) {
            if (freq[j] > freq[best] ||
               (freq[j] == freq[best] && strcmp(words[j], words[best]) < 0)) {
                best = j;
            }
        }
        if (best != i) {
            int tf = freq[i]; freq[i] = freq[best]; freq[best] = tf;
            char *tw = words[i]; words[i] = words[best]; words[best] = tw;
        }
    }
    FILE *f = fopen(path, "w");
    if (!f) { perror("fopen"); return; }
    for (int r = 0; r < n; r++) {
        fprintf(f, "%d %d %s\n", r + 1, freq[r], words[r]);
    }
    fclose(f);
}

static void print_hapax(char **words, int *freq, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) if (freq[i] == 1) total++;
    printf("Hapax legomena: %d\n", total);

    if (total == 0) return;

    printf("Some hapax: ");
    int shown = 0;
    for (int i = 0; i < n && shown < 10; i++) {
        if (freq[i] == 1) {
            printf("%s", words[i]);
            shown++;
            if (shown < total && shown < 10) printf(", ");
        }
    }
    printf("\n");
}

    
int main(){

    char* contents = NULL;
    char** words = NULL;
    int* frequencies = NULL;
    int nWords = 0;
    readBook("Moby_Dick.txt", &contents);
    countWords(contents,&words, &frequencies, &nWords);
    write_rank_freq_simple("rank_freq.txt", words, frequencies, nWords);
    //if (contents){
      //  printf("%s", contents);
    free(contents);
    //}
    return 0;}
    /**
   int main(int argc, char **argv){
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.txt> <output.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* contents = NULL;
    char** words = NULL;
    int* frequencies = NULL;
    int nWords = 0;

    readBook(argv[1], &contents);
    if (!contents) {  // readBook prints its own error
        return EXIT_FAILURE;
    }

    countWords(contents, &words, &frequencies, &nWords);
    if (!words || !frequencies) {
        free(contents);
        fprintf(stderr, "Error: counting words failed.\n");
        return EXIT_FAILURE;
    }

    // Milestone 1: hapax output
    print_hapax(words, frequencies, nWords);

    // Milestone 2: write "rank freq word" to the file given in argv[2]
    write_rank_freq_simple(argv[2], words, frequencies, nWords);
    printf("Wrote rank/frequency data to %s\n", argv[2]);

    // cleanup (free each strdup'ed word)
    for (int i = 0; i < nWords; ++i) free(words[i]);
    free(words);
    free(frequencies);
    free(contents);
    return EXIT_SUCCESS;
}


**/
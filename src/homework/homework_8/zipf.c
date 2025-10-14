# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
/**
* brief Reads the contents of the given file into a continuous array,
* any non-alphabetic character (numbers, symbols, ...) are replaced with a space.
* param fileName The name of the file to read
* param contents A pointer that will be allocated by the function and
contain the contents of the book.
**/

void readBook(const char *fileName, char **contents){
    FILE*  filePointer;
    size_t capacity;
    size_t currentLength;
    char*  bufferPointer;
    int    character;

    filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    capacity = 1024;
    currentLength = 0;
    bufferPointer = (char*)malloc(capacity);
    if (bufferPointer == NULL) {
        perror("malloc failed");
        fclose(filePointer);
        exit(EXIT_FAILURE);
    }

    character = fgetc(filePointer);
    while (character != EOF) {
        if (currentLength + 1 >= capacity) {
            size_t newCapacity;
            char*  newBuffer;

            newCapacity = capacity * 2;
            newBuffer = (char*)realloc(bufferPointer, newCapacity);
            if (newBuffer == NULL) {
                perror("realloc failed");
                free(bufferPointer);
                fclose(filePointer);
                exit(EXIT_FAILURE);
            }
            bufferPointer = newBuffer;
            capacity = newCapacity;
        }

        if (!isalpha((unsigned char)character)) {
            character = ' ';
        }
        bufferPointer[currentLength] = (char)character;
        currentLength += 1;

        character = fgetc(filePointer);
    }

    bufferPointer[currentLength] = '\0';
    fclose(filePointer);
    *contents = bufferPointer;
}
/**
* brief Counts the frequency of each word in the book.
* The caller is responsible for freeing the allocated memory.
* param book A continuous array of characters containing the book.
* param words A pointer to an array of strings that will be allocated
by the function and contain the unique words in the book.
* param frequencies A pointer to an array of integers that will be allocated
by the function and contain the frequency of each word in the book.
* param nWords A pointer to an integer that will be
set to the number of unique words in the book.
**/
static char* duplicateString(const char* source) {
    size_t length;
    char*  copy;

    length = strlen(source) + 1;
    copy = (char*)malloc(length);
    if (copy != NULL) {
        memcpy(copy, source, length);
    }
    return copy;
}

static int compareCStrings(const void* a, const void* b) {
    const char* const* leftPtr  = (const char* const*)a;
    const char* const* rightPtr = (const char* const*)b;
    return strcmp(*leftPtr, *rightPtr);
}

void countWords(const char* book, char*** words, int** frequencies, int* nWords) {
    char*  workBuffer;
    size_t i;

    workBuffer = duplicateString(book);
    if (workBuffer == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (workBuffer[i] != '\0') {
        if (isalpha((unsigned char)workBuffer[i])) {
            workBuffer[i] = (char)tolower((unsigned char)workBuffer[i]);
        }
        i += 1;
    }

    size_t tokensCapacity;
    size_t tokensCount;
    char** tokensArray;

    tokensCapacity = 128;
    tokensCount = 0;
    tokensArray = (char**)malloc(tokensCapacity * sizeof(char*));
    if (tokensArray == NULL) {
        perror("malloc failed");
        free(workBuffer);
        exit(EXIT_FAILURE);
    }

    char* token;
    token = strtok(workBuffer, " ");
    while (token != NULL) {
        if (token[0] != '\0') {
            if (tokensCount == tokensCapacity) {
                size_t newCapacity;
                char** newArray;

                newCapacity = tokensCapacity * 2;
                newArray = (char**)realloc(tokensArray, newCapacity * sizeof(char*));
                if (newArray == NULL) {
                    perror("realloc failed");
                    free(tokensArray);
                    free(workBuffer);
                    exit(EXIT_FAILURE);
                }
                tokensArray = newArray;
                tokensCapacity = newCapacity;
            }

            char* tokenCopy;
            tokenCopy = duplicateString(token);
            if (tokenCopy == NULL) {
                perror("malloc failed");
                size_t k;
                for (k = 0; k < tokensCount; ++k) {
                    free(tokensArray[k]);
                }
                free(tokensArray);
                free(workBuffer);
                exit(EXIT_FAILURE);
            }

            tokensArray[tokensCount] = tokenCopy;
            tokensCount += 1;
        }

        token = strtok(NULL, " ");
    }

    free(workBuffer);

    if (tokensCount == 0) {
        *words = NULL;
        *frequencies = NULL;
        *nWords = 0;
        free(tokensArray);
        return;
    }

    qsort(tokensArray, tokensCount, sizeof(char*), compareCStrings);

    size_t uniqueCapacity;
    size_t uniqueCount;
    char** uniqueWords;
    int*   uniqueFreqs;

    uniqueCapacity = 128;
    uniqueCount = 0;
    uniqueWords = (char**)malloc(uniqueCapacity * sizeof(char*));
    uniqueFreqs = (int*)malloc(uniqueCapacity * sizeof(int));
    if (uniqueWords == NULL || uniqueFreqs == NULL) {
        perror("malloc failed");
        free(uniqueWords);
        free(uniqueFreqs);
        size_t k;
        for (k = 0; k < tokensCount; ++k) {
            free(tokensArray[k]);
        }
        free(tokensArray);
        exit(EXIT_FAILURE);
    }

    uniqueWords[0] = tokensArray[0];
    uniqueFreqs[0] = 1;
    uniqueCount = 1;

    for (i = 1; i < tokensCount; ++i) {
        if (strcmp(tokensArray[i], uniqueWords[uniqueCount - 1]) == 0) {
            uniqueFreqs[uniqueCount - 1] += 1;
            free(tokensArray[i]);
        } else {
            if (uniqueCount == uniqueCapacity) {
                size_t newCapacity;
                char** newWords;
                int*   newFreqs;

                newCapacity = uniqueCapacity * 2;
                newWords = (char**)realloc(uniqueWords, newCapacity * sizeof(char*));
                newFreqs = (int*)realloc(uniqueFreqs, newCapacity * sizeof(int));
                if (newWords == NULL || newFreqs == NULL) {
                    perror("realloc failed");
                    size_t r;
                    for (r = i; r < tokensCount; ++r) {
                        free(tokensArray[r]);
                    }
                    size_t w;
                    for (w = 0; w < uniqueCount; ++w) {
                        free(uniqueWords[w]);
                    }
                    free(uniqueWords);
                    free(uniqueFreqs);
                    free(tokensArray);
                    exit(EXIT_FAILURE);
                }
                uniqueWords = newWords;
                uniqueFreqs = newFreqs;
                uniqueCapacity = newCapacity;
            }
            uniqueWords[uniqueCount] = tokensArray[i];
            uniqueFreqs[uniqueCount] = 1;
            uniqueCount += 1;
        }
    }

    free(tokensArray);

 
    *words = (char**)realloc(uniqueWords, uniqueCount * sizeof(char*));
    if (*words == NULL) {
        *words = uniqueWords;
    }
    *frequencies = (int*)realloc(uniqueFreqs, uniqueCount * sizeof(int));
    if (*frequencies == NULL) {
        *frequencies = uniqueFreqs;
    }
    *nWords = (int)uniqueCount;
}

typedef struct {
    char* word;
    int   frequency;
} WordFrequency;

static int compareByFrequencyDesc(const void* a, const void* b) {
    const WordFrequency* wa = (const WordFrequency*)a;
    const WordFrequency* wb = (const WordFrequency*)b;

    if (wa->frequency > wb->frequency) return -1;
    if (wa->frequency < wb->frequency) return  1;
    return strcmp(wa->word, wb->word);
}
void writeRankFreq(const char* outputFileName,
                   char** words,
                   int* frequencies,
                   int numberOfUniqueWords) {
    FILE* outFile;
    WordFrequency* array;
    int i;
    int rank;

    outFile = fopen(outputFileName, "w");
    if (outFile == NULL) {
        perror("Error opening output file");
        return; /* simple handling is fine at this stage */
    }

    array = (WordFrequency*)malloc((size_t)numberOfUniqueWords * sizeof(WordFrequency));
    if (array == NULL) {
        perror("malloc failed");
        fclose(outFile);
        return;
    }

    for (i = 0; i < numberOfUniqueWords; ++i) {
        array[i].word = words[i];
        array[i].frequency = frequencies[i];
    }

    qsort(array, (size_t)numberOfUniqueWords, sizeof(WordFrequency), compareByFrequencyDesc);

    rank = 1; /* rank starts at 1 as the notes say */
    for (i = 0; i < numberOfUniqueWords; ++i) {
        fprintf(outFile, "%d %d %s\n", rank, array[i].frequency, array[i].word);
        rank += 1;
    }

    free(array);
    fclose(outFile);
}
void printHapaxSample(char** words, int* frequencies, int numberOfUniqueWords) {
    int count;
    int i;
    int printed;

    count = 0;
    for (i = 0; i < numberOfUniqueWords; ++i) {
        if (frequencies[i] == 1) {
            count += 1;
        }
    }

    printf("Hapax legomena (occur exactly once): %d\n", count);

    printed = 0;
    printf("Some examples: ");
    for (i = 0; i < numberOfUniqueWords && printed < 20; ++i) {
        if (frequencies[i] == 1) {
            printf("%s ", words[i]);
            printed += 1;
        }
    }
    printf("\n");
}

int main(int argc, char** argv) {
    char* bookContents;
    char** wordsArray;
    int* frequenciesArray;
    int numberOfUniqueWords;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.txt output.dat\n", argv[0]);
        return EXIT_FAILURE;
    }
    readBook(argv[1], &bookContents);
    countWords(bookContents, &wordsArray, &frequenciesArray, &numberOfUniqueWords);
    writeRankFreq(argv[2], wordsArray, frequenciesArray, numberOfUniqueWords);
    printHapaxSample(wordsArray, frequenciesArray, numberOfUniqueWords);
    {
        int i;
        free(bookContents);
        for (i = 0; i < numberOfUniqueWords; ++i) {
            free(wordsArray[i]);
        }
        free(wordsArray);
        free (frequenciesArray);
    }

    return EXIT_SUCCESS;
}
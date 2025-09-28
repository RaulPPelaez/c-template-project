# ifndef LIBRARY2_H
# define LIBRARY2_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int append_one(int **arr, size_t *len, int value);

int read_input(int **arr, size_t *len);

int operations(int *arr, size_t len);

# endif // LIBRARY2_H
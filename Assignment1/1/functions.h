#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

void reverseString(char *str, int length);
char *compressString(char *str, int length);
int *uniqueElements(int *arr, int length);
int **transpose(int **matrix, int NumRow, int NumCol);

#endif
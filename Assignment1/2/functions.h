#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void qsort_int(int arr[], int len);

int *intersectionArray(int *arr1, int *arr2, int lenArr1, int lenArr2);
int countCharOccurences(const char *str, int length, char ch);
char findFirstNonRepeatingChar(const char *str, int length);
char *findLongesetCommonPrefix(char **str, int numStr, int maxLen);
int *maxMin(int *arr, int lenArr);
char *removeSubstring(char *str, int strLength, const char *substr, int substrLength);

#endif
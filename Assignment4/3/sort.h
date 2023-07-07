#ifndef MERGE_H
#define MERGE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node *ptr;
struct node
{
    int len;
    char *str;
};

ptr createnode(int len, char *str);
void printarr(int n, ptr *arr);

// SORTING STARTS HERE
int compare(ptr a, ptr b);
ptr *create(int n);
void merge(int start, int middle, int end, ptr *arr, ptr *l, ptr *r, int sl, int sr);
void mergesort(ptr *arr, int start, int end);
// SORTING ENDS HERE

#endif
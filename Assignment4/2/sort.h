#ifndef MERGE_H
#define MERGE_H

#include <stdio.h>
#include <stdlib.h>

int *create(int n);
void merge(int start, int middle, int end, int *arr, int *b, int *l, int *r, int *lb, int *rb, int sl, int sr);
void mergesort(int *a, int *b, int start, int end);

#endif
#ifndef MERGE_H
#define MERGE_H

#include <stdio.h>
#include <stdlib.h>

int *create(int n);
void merge(int start, int middle, int end, int *arr, int *l, int *r, int sl, int sr);
void mergesort(int *arr, int start, int end);

#endif

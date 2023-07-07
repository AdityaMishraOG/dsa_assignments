#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#define int long long

void swap(int *a, int *b);
void heap(int n, int *a);
void percdown(int n, int *a);
void print(int n, int *a);

#endif
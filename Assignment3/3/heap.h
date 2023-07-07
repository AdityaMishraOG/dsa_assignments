#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef struct HeapSt *Heap;
struct HeapSt
{
    int capacity;
    int size;
    int *arr;
};

int isEmpty(Heap h);
int isFull(Heap h);
Heap createHeap(int capacity);
void insertIntoHeap(int value, Heap h);
int extractMin(Heap h);

#endif
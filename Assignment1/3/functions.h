#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
// BASIC SKELETON OF THE CODE
typedef struct Node *PtrNode;
struct Node
{
    int element;
    PtrNode NextNode;
};

PtrNode createNode(int val);

void Insert(PtrNode Head, int num);

PtrNode Find(PtrNode Head, int num);

void Print(PtrNode Head);

#endif
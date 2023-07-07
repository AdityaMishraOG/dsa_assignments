#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Queue;
typedef struct Node *PtrNode;
struct Node
{
    int value;
    PtrNode next;
    PtrNode prev;
};

Queue createNode(int val);
void Push(Queue head, int val);
int Pop(Queue head);
void Inject(Queue head, int val);
int popRear(Queue head);
void Print(Queue head);
void PrintReverse(Queue head);
int findElem(Queue head, int pos);
void removeKElems(Queue head, int k);

#endif
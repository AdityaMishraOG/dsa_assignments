#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StackStructure *Stack;
struct StackStructure
{
    char *Elements;
    int MaxCapacity;
    int TopIndex;
};

int IsFull(Stack S);
int IsEmpty(Stack S);
int Push(Stack S, char ch);
char Pop(Stack S);
char Top(Stack S);
Stack CreateStack(int MaxCapacity);
int Balanced(char *str, int len);
int Palindrome(char *str, int len);

#endif

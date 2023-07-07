#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
// MULTIPLICATION STUFF STARTS

typedef struct RowNode *PtrRowNode;
typedef struct ErectNode *PtrErectNode;

struct RowNode
{
    int rownumber;
    PtrRowNode NextRow;
    PtrErectNode Next;
};

struct ErectNode
{
    int column;
    int value;
    PtrErectNode Next;
};

// MULTIPLICATION STUFF ENDS

typedef struct Node *PtrNode;
struct Node
{
    int row;
    int column;
    int value;
    // PtrNode next;
};

void copy_array(PtrNode *A, int start, int end, PtrNode *B);
void merge(PtrNode *L, int sL, PtrNode *R, int sR, PtrNode *A);
PtrNode createNode(int row, int col, int value);
void sortnodes(PtrNode *A, int len);
void printNodes(PtrNode *A, int len);
int countNonZeroNodes(PtrNode *A, int len);
void printAllNodes(PtrNode *A, int len);
// MULTIPLICATION STUFF STARTS
void copy_array_mul(int **A, int start, int end, int **B);
void merge_mul(int **L, int sL, int **R, int sR, int **A);
void sort_mul(int **A, int len);
PtrRowNode createRowNode(int rownumber);
PtrErectNode createErectNode(int column, int value);
PtrRowNode Insert(PtrRowNode currentRowNode, int row, int column, int value);
PtrRowNode createMatrix(int n, int m, int k);
PtrRowNode createTranspose(int n, int m, int k);
PtrRowNode displayMatrix(PtrRowNode Head, int k);
void deleteMatrix(PtrRowNode Head);
int multiplycount(PtrRowNode Head1, PtrRowNode Head2);
void multiply(PtrRowNode Head1, PtrRowNode Head2);
// MULTIPLICATION STUFF ENDS

#endif
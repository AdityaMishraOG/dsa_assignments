#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INVAL -1
// #define TABLE_SIZE 5000009
#define TABLE_SIZE 8000009
// #define TABLE_SIZE 1000000007
#define int64 long long
// #define i long long int64
extern int count;

typedef struct NodeStructure *Node;
struct NodeStructure
{
    int64 len;
    char *str;
    Node next;
    int64 hash2;
};

typedef struct HashStructure *HashTable;
struct HashStructure
{
    long long size;
    Node *start;
};

// GLOBAL VARIABLE count IS DEFINED

Node createNode(int64 len, char *str, int64 hash2);
int64 map3(char ch);
int64 Hash(int64 len, char *str);
int64 Hash2(int64 len, char *str);
HashTable create(long long size);
HashTable insert(int64 len, char *str, int64 hash2, HashTable h);
void printAnagrams(int64 len, char *str, int64 hash2, Node currentNode);

#endif
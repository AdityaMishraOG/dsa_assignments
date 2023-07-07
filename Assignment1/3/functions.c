#include "functions.h"

PtrNode createNode(int val)
{
    PtrNode ret = (PtrNode)malloc(sizeof(struct Node));
    ret->element = val;
    ret->NextNode = NULL;
    return ret;
}

void Insert(PtrNode Head, int num)
{
    PtrNode nod = createNode(num);
    nod->NextNode = Head->NextNode;
    Head->NextNode = nod;
    PtrNode second = Head->NextNode;
    // PtrNode third = second->NextNode;
    PtrNode last = second->NextNode;
    if (last == NULL)
    {
        second->NextNode = second;
        return;
    }
    while (last->NextNode != second->NextNode)
    {
        last = last->NextNode;
    }
    last->NextNode = nod;
}

PtrNode Find(PtrNode Head, int num)
{
    // if num doesn't exist, then return NULL

    // if Head points to NULL
    if (Head->NextNode == NULL)
    {
        return NULL;
    }
    PtrNode second = Head->NextNode;
    // if only one element exists
    if (second->NextNode == second)
    {
        if (second->element == num)
        {
            return second;
        }
        else
        {
            return NULL;
        }
    }

    PtrNode nod = second->NextNode;
    PtrNode prev = second;
    // if multiple elements exist and second is the answer
    if (second->element == num)
    {
        return second;
    }
    // if multiple elements exist and second is not the answer
    while (nod->element != num && nod != second)
    {
        nod = nod->NextNode;
        prev = prev->NextNode;
    }
    // if num doesn't exist in the linked list
    if (nod == second)
    {
        return NULL;
    }
    // if num does exist in the linked list
    prev->NextNode = nod->NextNode;
    free(nod);
    Insert(Head, num);
    return Head->NextNode;
}

void Print(PtrNode Head)
{
    if (Head->NextNode == NULL)
    {
        // printf("\n");
        return;
    }
    PtrNode second = Head->NextNode;
    PtrNode runner = Head->NextNode;
    printf("%d ", runner->element);
    runner = runner->NextNode;
    while (runner != second)
    {
        printf("%d ", runner->element);
        runner = runner->NextNode;
    }
    printf("\n");
}

#include "heap.h"


///////////////////////////////////////////////
// WE KEEP A DUMMY NODE AT arr[0] = INT_MIN //
// HENCE, INITIAL SIZE = 0 AND WE NEED TO  //
// GIVE THE ARRAY A SIZE capacity + 1     //
///////////////////////////////////////////

int isEmpty(Heap h)
{
    if (h->size == 0)
    {
        return 1;
    }
    return 0;
}

int isFull(Heap h)
{
    if (h->size + 1 == h->capacity)
    {
        return 1;
    }
    return 0;
}

Heap createHeap(int capacity)
{
    Heap ret = (Heap)malloc(sizeof(struct HeapSt));
    assert(ret != NULL);
    ret->capacity = 1 + capacity;
    ret->arr = (int *)malloc((1 + capacity) * sizeof(int));
    assert(ret->arr != NULL);
    // assert(dominance)
    ret->arr[0] = INT_MIN;
    ret->size = 0;
    return ret;
}

void insertIntoHeap(int value, Heap h)
{
    if (isFull(h))
    {
        fprintf(stderr, "Heap is already full!");
        return;
    }

    int i;
    for (i = ++h->size; h->arr[i / 2] > value; i /= 2)
    {
        h->arr[i] = h->arr[i / 2];
    }
    h->arr[i] = value;
    return;
}

int extractMin(Heap h)
{
    if (isEmpty(h))
    {
        fprintf(stderr, "Heap is already empty!");
        return INT_MIN;
    }
    int i;
    int minElement, last;

    minElement = h->arr[1];
    last = h->arr[h->size--];

    int child;
    for (i = 1; i * 2 <= h->size; i = child)
    {
        child = 2 * i;
        if ((child != h->size) && (h->arr[child + 1] < h->arr[child]))
        {
            child++;
        }
        ///////////////////////////////////////////
        // CHECK IF LAST NEEDS TO PERCOLATE DOWN //
        // IN WHICH CASE, CHILD NEEDS TO MOVE UP //
        // OR WE FIND THE PLACE TO INSERT LAST   //
        ///////////////////////////////////////////
        if (last > h->arr[child])
        {
            h->arr[i] = h->arr[child];
        }
        else
        {
            break;
        }
    }
    h->arr[i] = last;
    return minElement;
}

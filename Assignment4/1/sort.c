#include "sort.h"

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void heap(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        int parent;
        for (j = i; j > 0; j = parent)
        {
            parent = (j - 1) / 2;
            if (a[j] > a[parent])
            {
                swap(a + j, a + parent);
            }
            if (j == 0)
            {
                break;
            }
        }
    }
}

void percdown(int n, int *a)
{
    int i, child = 1;
    for (i = 0; 2 * i + 1 < n; i = child)
    {
        child = 2 * i + 1;
        if (child + 1 < n && a[child + 1] > a[child])
        {
            child++;
        }
        if (a[child] > a[i])
        {
            swap(a + child, a + i);
        }
    }
}

void print(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", a[i]);
    }
    printf("\n");
}

#include "sort.h"

ptr createnode(int len, char *str)
{
    ptr ret = (ptr)malloc(sizeof(struct node));
    ret->len = len;
    ret->str = (char *)malloc((len + 1) * sizeof(char));
    ret->str = str;
    return ret;
}

void printarr(int n, ptr *arr)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]->str);
    }
    // printf("\n");
}

// SORTING STARTS HERE

int compare(ptr a, ptr b)
{
    // We return 1 when
    // it is an odd position and A has a letter that appears earlier in the alphabet than the corresponding letter in B
    // it is an even position and A has a letter that appears later in the alphabet than the corresponding letter in B
    // A is a prefix of B and A has an odd length
    // B is a prefix of A and B has an even length

    int i = 0;
    while (a->str[i] == b->str[i] && i != a->len && i != b->len)
    {
        i++;
    }
    if (i == a->len) // a is a prefix of b
    {
        // a = xy
        // b = xyz
        if (a->len % 2) // length of a is odd
        {
            return 1;
        }
        else // length of a is even
        {
            return -1;
        }
    }
    if (i == b->len) // b is a prefix of a
    {

        if (b->len % 2) // length of b is odd
        {
            return -1;
        }
        else // length of b is even
        {
            return 1;
        }
    }

    char ach = a->str[i];
    char bch = b->str[i];
    if (ach > bch)
    {
        if (i % 2 == 0) // in one based indexing, i is ODD
        {
            return -1;
        }
        else // i is EVEN in one-based indexing
        {
            return 1;
        }
    }
    else
    {
        if (i % 2 == 0) // i is ODD in one-based indexing
        {
            return 1;
        }
        else // i is EVEN in one-based indexing
        {
            return -1;
        }
    }
}

ptr *create(int n)
{
    ptr *ret = (ptr *)malloc(n * sizeof(ptr));
    return ret;
}

void merge(int start, int middle, int end, ptr *arr, ptr *l, ptr *r, int sl, int sr)
{
    int i = 0;
    int j = 0;
    int k = start;
    while (i != sl && j != sr)
    {
        if (compare(l[i], r[j]) < 0)
        {
            arr[k++] = r[j++];
        }
        else
        {
            arr[k++] = l[i++];
        }
    }
    while (i != sl)
    {
        arr[k++] = l[i++];
    }
    while (j != sr)
    {
        arr[k++] = r[j++];
    }
}

void mergesort(ptr *arr, int start, int end)
{
    // printf("in\n");

    if (start < end)
    {
        int middle = (start + end) / 2;

        ptr *l = create(middle + 1 - start);
        ptr *r = create(end - middle);
        int j = 0;
        for (int i = start; i < middle + 1; i++)
        {
            l[j++] = arr[i];
        }
        j = 0;
        for (int i = middle + 1; i < end + 1; i++)
        {
            r[j++] = arr[i];
        }

        mergesort(l, 0, middle - start);
        mergesort(r, 0, end - middle - 1);

        //////////////////////////////////////////////
        //        printf("l is: ");
        //        print(middle + 1 - start, l);
        //        printf("r is: ");
        //        print(end - middle, r);
        ////////////////////////////////////////////
        merge(start, middle, end, arr, l, r, middle - start + 1, end - middle);
        // FREE HERE
    }
}

// SORTING ENDS HERE
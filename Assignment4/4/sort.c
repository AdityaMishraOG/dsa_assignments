#include "sort.h"

int *create(int n)
{
    int *ret = (int *)malloc(n * sizeof(int));
    return ret;
}

void merge(int start, int middle, int end, int *arr, int *l, int *r, int sl, int sr)
{
    int i = 0;
    int j = 0;
    int k = start;
    while (i != sl && j != sr)
    {
        if (l[i] < r[j])
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

void mergesort(int *arr, int start, int end)
{
    // printf("in\n");

    if (start < end)
    {
        int middle = (start + end) / 2;

        int *l = create(middle + 1 - start);
        int *r = create(end - middle);
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
        free(l);
        free(r);
    }
}

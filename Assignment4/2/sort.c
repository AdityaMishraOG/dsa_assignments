#include "sort.h"


int *create(int n)
{
    int *ret = (int *)malloc(n * sizeof(int));
    return ret;
}

void merge(int start, int middle, int end, int *arr, int *b, int *l, int *r, int *lb, int *rb, int sl, int sr)
{
    int i = 0;
    int j = 0;
    int k = start;
    while (i != sl && j != sr)
    {
        if (l[i] > r[j])
        {
            b[k] = rb[j];
            arr[k++] = r[j++];
        }
        else if (l[i] < r[j])
        {
            b[k] = lb[i];
            arr[k++] = l[i++];
        }
        else
        {
            if (lb[i] < rb[j])
            {
                b[k] = lb[i];
                arr[k++] = l[i++];
            }
            else
            {
                b[k] = rb[j];
                arr[k++] = r[j++];
            }
        }
    }
    while (i != sl)
    {
        b[k] = lb[i];
        arr[k++] = l[i++];
    }
    while (j != sr)
    {
        b[k] = rb[j];
        arr[k++] = r[j++];
    }
}

void mergesort(int *a, int *b, int start, int end)
{
    // printf("in\n");

    if (start < end)
    {
        int middle = (start + end) / 2;

        int *l = create(middle + 1 - start);
        int *r = create(end - middle);
        int *lb = create(middle + 1 - start);
        int *rb = create(end - middle);

        int j = 0;
        int j2 = 0;
        for (int i = start; i < middle + 1; i++)
        {
            l[j++] = a[i];
            lb[j2++] = b[i];
        }
        j = 0;
        j2 = 0;
        for (int i = middle + 1; i < end + 1; i++)
        {
            r[j++] = a[i];
            rb[j2++] = b[i];
        }

        mergesort(l, lb, 0, middle - start);
        mergesort(r, rb, 0, end - middle - 1);

        //////////////////////////////////////////////
        //  printf("l is: ");
        //  print(middle + 1 - start, l);
        //  printf("r is: ");
        //  print(end - middle, r);
        //  printf("lb is: ");
        //  print(middle + 1 - start, lb);
        //  printf("rb is: ");
        //  print(end - middle, r);
        ////////////////////////////////////////////

        merge(start, middle, end, a, b, l, r, lb, rb, middle - start + 1, end - middle);
        free(l);
        free(r);
        free(lb);
        free(rb);
    }
}

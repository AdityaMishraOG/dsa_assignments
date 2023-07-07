#include "heap.h"

int main()
{
    int n;
    scanf("%d", &n);

    if (n == 1)
    {
        int x;
        scanf("%d", &x);
        printf("%d", x);
    }

    int a[n];
    int b[n];

    Heap h = createHeap(n + 2);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        insertIntoHeap(x, h);
        a[i] = x;
    }
    int swap_flag = 0;
    for (int i = 0; i < n; i++)
    {
        int ext = extractMin(h);
        if (ext != a[i])
        {
            // printf("%d ", ext);
            b[i] = ext;
        }
        else
        {
            if (!isEmpty(h))
            {
                int second_ext = extractMin(h);
                // printf("%d ", second_ext);
                b[i] = second_ext;
                insertIntoHeap(ext, h);
            }
            else
            {
                b[i] = ext;
                swap_flag = 1;
            }
        }
    }
    if (swap_flag)
    {
        int temp = b[n - 1];
        b[n - 1] = b[n - 2];
        b[n - 2] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    return 0;
}

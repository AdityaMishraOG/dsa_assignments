#include "sort.h"

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int *a = (int *)malloc(n * sizeof(int));
        int *b = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", b + i);
        }

        mergesort(a, b, 0, n - 1);
        // print(n, a);
        // print(n, b);

        int previously_printed_value = -1;
        int up = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i] && a[i] >= previously_printed_value)
            {
                // printf("%d ", a[i]);
                previously_printed_value = a[i];
                up = 1;
            }
            else if (b[i] < a[i] && b[i] >= previously_printed_value)
            {
                // printf("%d ", b[i]);
                previously_printed_value = b[i];
                up = 0;
            }
            else
            {
                if (a[i] >= previously_printed_value)
                {
                    // printf("%d ", a[i]);
                    previously_printed_value = a[i];
                    up = 1;
                }
                else
                {
                    // printf("%d ", b[i]);
                    previously_printed_value = b[i];
                    up = 0;
                }
            }
        }
        // printf("\n");
        if (up)
        {
            printf("%d %d\n", a[n - 1], a[n - 1]);
        }
        else
        {
            printf("%d %d\n", a[n - 1], b[n - 1]);
        }
        // printf("%d %d\n", a[n - 1], previously_printed_value);
    }

    // sort()

    return 0;
}
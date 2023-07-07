#include "sort.h"

int main()
{
    int t;
    scanf("%lld", &t);

    while (t--)
    {
        int n, k;
        scanf("%lld%lld", &n, &k);
        int *a = (int *)calloc((n + 1), sizeof(int));
        // long long max_count = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            // max_count += ((long long)a[i] * ((long long)a[i] - 1) / 2);
            // heap(n, a);
        }
        // print(n, a);
        heap(n, a);
        // printf("After heapifying...\n");
        // print(n, a);
        // printf("\n");
        int count = 0;
        while (k--)
        {
            if (a[0] <= 0)
            {
                break;
            }

            count += a[0];
            a[0]--;
            if (a[0] <= a[1] || a[0] <= a[2])
            {
                percdown(n, a);
            }
            // print(n, a);
        }
        printf("%lld\n", count);
    }
    return 0;
}
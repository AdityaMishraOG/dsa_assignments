#include "sort.h"

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m); // n is height, m is width
        int **a = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++)
        {
            a[i] = (int *)malloc(m * sizeof(int));
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                scanf("%d", &x);
                a[j][i] = x;
            }
        }
        int j;
        scanf("%d", &j);
        j--;
        int *my_school = (int *)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++)
        {
            my_school[i] = a[j][i];
        }

        int *best = (int *)malloc(m * sizeof(int)); // contains the best opponent for each i-> 0 to m - 1

        for (int i = 0; i < m; i++)
        {
            int mx = -1;
            for (int k = 0; k < n; k++)
            {
                if (k == j)
                {
                    continue;
                }
                int cur = a[k][i];
                if (mx < cur)
                {
                    mx = cur;
                };
            }
            best[i] = mx;
        }
        mergesort(my_school, 0, m - 1);
        mergesort(best, 0, m - 1);

        int count = 0; // traverses my_school[] from front
        int i = 0;     // traverses best[] from behind
        int ans = 0;
        while (i != m)
        {
            if (my_school[count] > best[i])
            {
                // printf("best[%d]=%d\n", i, best[i]);
                // printf("my_school[%d]=%d\n\n", count, my_school[count]);
                count++;
                i++;
                ans;
            }
            else
            {
                i++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
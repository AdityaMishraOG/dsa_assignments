#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

int **Create2D(int n, int m, int k)
{
    int **ret = (int **)malloc((n + 1) * sizeof(int *));
    // assert(ret != NULL);
    for (int i = 0; i < n + 1; i++)
    {
        ret[i] = (int *)malloc((m + 1) * sizeof(int));
        // assert(ret[i] != NULL);
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            ret[i][j] = 1;
        }
    }

    while (k--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        ret[a][b] = 0;
    }
    return ret;
}

void Print2D(int n, int m, int **a)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int MaximumValue(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int ChangeInPerimeter(int i, int j, int n, int m, int **a)
{
    int ret = 4;
    if (i > 1 && a[i - 1][j] == 2)
    {
        ret -= 2;
        // printf("1->\n");
    }
    // printf("61\n");
    if (j > 1 && a[i][j - 1] == 2)
    {
        ret -= 2;
        // printf("2->\n");
    }
    // printf("67\n");
    if (i < n && a[i + 1][j] == 2)
    {
        ret -= 2;
        // printf("3->\n");
    }
    // printf("73\n");
    if (j < m && a[i][j + 1] == 2)
    {
        ret -= 2;
        // printf("4->\n");
    }
    // printf("79\n");
    return ret;
}

void FindMaximumProfit(int i, int j, int n, int m, int **a, int *area, int *perimeter)
{
    // printf("\ti is %d, j is %d\n", i, j);
    // Print2D(n, m, a);

    // printf("a[i][j] = %d\n", a[i][j]);
    if (a[i][j] == 0)
    {
        a[i][j] = 2;
        *area += 4;
        int change = ChangeInPerimeter(i, j, n, m, a);
        *perimeter += change;
        if (i + 1 < n + 1)
        {
            FindMaximumProfit(i + 1, j, n, m, a, area, perimeter);
        }
        if (j + 1 < m + 1)
        {
            FindMaximumProfit(i, j + 1, n, m, a, area, perimeter);
        }
        if (i > 1)
        {
            FindMaximumProfit(i - 1, j, n, m, a, area, perimeter);
        }
        if (j > 1)
        {
            FindMaximumProfit(i, j - 1, n, m, a, area, perimeter);
        }
    }
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int **a = Create2D(n, m, k);
    // Print2D(n, m, a);

    int ans = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (a[i][j] == 0)
            {
                // printf("i = %d, j = %d\n", i, j);
                // Print2D(n, m, a);
                int area = 0;
                int perimeter = 0;
                // printf("running f...\n");
                FindMaximumProfit(i, j, n, m, a, &area, &perimeter);
                // printf("done with f!\n");
                int profit = area - perimeter;

                ans = MaximumValue(ans, profit);
            }
        }
    }

    // printf("\n");
    // Print2D(n, m, a);
    // printf("\n");

    printf("%d\n", ans);
    return 0;
}
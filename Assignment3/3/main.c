#include "heap.h"

int main()
{
    int n;
    scanf("%d", &n);

    Heap h = createHeap(n + 2);
    int count = 0;
    long long sum = 0;
    while (n--)
    {
        int x;
        scanf("%d", &x);

        if (x >= 0)
        {
            // printf("sum is %d initially...\n", sum);
            while (sum < 0)
            {
                int ext = extractMin(h);
                sum -= (ext);
                count--;
            }
            // printf("sum is %d when x is %d\n", sum, x);
            sum += x;
            count++;
            insertIntoHeap(x, h);
        }
        else
        {
            insertIntoHeap(x, h);
            sum += x;
            count++;
        }
    }
    while (sum < 0)
    {
        int ext = extractMin(h);
        sum -= ext;
        count--;
    }
    // printf("Final sum is %d\n", sum);
    // printf("Count is %d\n", count);
    printf("%d\n", count);
    return 0;
}

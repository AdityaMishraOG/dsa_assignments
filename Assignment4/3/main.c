#include "sort.h"

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        ptr *arr = (ptr *)malloc(n * sizeof(struct node));

        // printf("Entering for loop...\n");
        for (int i = 0; i < n; i++)
        {
            // printf("i is %d\n", i);
            int len;
            scanf("%d", &len);
            char *str = (char *)malloc((len + 1) * sizeof(char));
            scanf("%s", str);
            arr[i] = createnode(len, str);
        }
        // printf("\n");
        // printarr(n, arr);
        mergesort(arr, 0, n - 1);

        // printf("After sorting...\n");
        printarr(n, arr);
    }

    return 0;
}
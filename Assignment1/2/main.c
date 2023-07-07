#include "functions.h"

int main()
{
    int t;
    scanf("%d", &t);
    char correction;
    scanf("%c", &correction);
    while (t--)
    {
        char *s = (char *)malloc(6 * sizeof(char));
        scanf("%s", s);
        if (s[4] == '1')
        {
            int n1, n2;
            scanf("%d%d", &n1, &n2);
            int arr1[n1], arr2[n2];
            for (int i = 0; i < n1; i++)
            {
                scanf("%d", &arr1[i]);
            }
            for (int i = 0; i < n2; i++)
            {
                scanf("%d", &arr2[i]);
            }
            qsort_int(arr1, n1);
            qsort_int(arr2, n2);

            int *ret = intersectionArray(arr1, arr2, n1, n2);
            for (int i = 1; i < ret[0]; i++)
            {
                printf("%d ", ret[i]);
            }
            printf("\n");
        }
        else if (s[4] == '2')
        {
            int n;
            scanf("%d\n", &n);
            char *str = (char *)malloc((n + 1) * sizeof(char));
            scanf("%s\n", str);
            char ch;
            scanf("%c", &ch);
            int ans = countCharOccurences(str, n, ch);
            printf("%d\n", ans);
        }
        else if (s[4] == '3')
        {
            int n;
            scanf("%d\n", &n);
            char *str = (char *)malloc((n + 1) * sizeof(char));
            scanf("%s", str);
            char retchar = findFirstNonRepeatingChar(str, n);
            if (retchar == 1)
            {
                printf("-1\n");
            }
            else
            {
                printf("%c\n", retchar);
            }
        }
        else if (s[4] == '4')
        {
            int n;
            scanf("%d\n", &n);
            char **str = (char **)malloc(n * sizeof(char *));
            int maxLen = 0;

            for (int i = 0; i < n; i++)
            {
                int len;
                scanf("%d\n", &len);
                if (len > maxLen)
                {
                    maxLen = len;
                }
                str[i] = (char *)malloc((len + 1) * sizeof(char));
                scanf("%s", str[i]);
            }
            // printf("maxlen is: %d\n", maxLen);
            char *ret = findLongesetCommonPrefix(str, n, maxLen);
            if (ret[0] == '1')
            {
                printf("-1\n");
            }
            else
            {
                printf("%s\n", ret);
            }
        }
        else if (s[4] == '5')
        {
            int n;
            scanf("%d\n", &n);
            int *arr = (int *)malloc(n * sizeof(int));
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            int *ret = maxMin(arr, n);
            if (ret[0] == 1)
            {
                printf("-1\n");
            }
            else
            {
                for (int i = 1; i < ret[0]; i++)
                {
                    printf("%d ", ret[i]);
                }
                printf("\n");
            }
        }
        else if (s[4] == '6')
        {
            int n, m;
            scanf("%d%d\n", &n, &m);
            char *str = (char *)malloc(n * sizeof(char));
            char *subStr = (char *)malloc(m * sizeof(char));
            scanf("%s", str);
            scanf("%s", subStr);
            char *ret = removeSubstring(str, n, subStr, m);

            printf("%s\n", ret);
        }
        else
        {
            printf("There is something wrong with the if statements!\n");
        }
    }
    return 0;
}
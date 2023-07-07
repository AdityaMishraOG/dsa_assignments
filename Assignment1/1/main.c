#include "functions.h"

int main()
{
    // char *s = "aaabcc";
    // int l = 6;
    // char *r = compressString(s, l);
    // printf("%s", r);

    // // UNIQUE_ELEMENTS
    //     int l1 = 8;
    //     int a[] = {1, 3, 7, 3, 2, 1, 4, 5, 5, 2};

    //     // printf("%d", l1);
    //     int *b = uniqueElements(a, l1);
    //     for (int i = 1; i < b[0]; i++)
    //     {
    //         printf("%d ", b[i]);
    //     }

    // // TRANSPOSE
    // int **matrix = (int **)malloc(3 * sizeof(int *));
    // for (int i = 0; i < 3; i++)
    // {
    //     matrix[i] = (int *)malloc(2 * sizeof(int));
    // }
    // int val = 1;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         matrix[i][j] = val;
    //         val++;
    //     }
    // }

    // int **trans = transpose(matrix, 3, 2);
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%d ", trans[i][j]);
    //     }
    //     printf("\n");
    // }

    int t;
    scanf("%d", &t);

    char ch;
    scanf("%c", &ch);

    while (t--)
    {
        char *s = (char *)malloc(6 * sizeof(char));
        scanf("%s", s);
        // printf("%s", s);

        if (s[4] == '1')
        {
            int length;
            scanf("%d", &length);
            scanf("%c", &ch);
            char *str = (char *)malloc((length + 1) * sizeof(char));
            scanf("%s", str);
            reverseString(str, length);
            printf("%s\n", str);
            free(str);
        }
        else if (s[4] == '2')
        {
            int length;
            scanf("%d", &length);
            char *str = (char *)malloc((length + 1) * sizeof(char));
            scanf("%s", str);
            char *ret = compressString(str, length);
            printf("%s\n", ret);
            free(ret);
        }
        else if (s[4] == '3')
        {
            int length;
            scanf("%d", &length);
            int *arr = (int *)malloc(length * sizeof(int));
            for (int i = 0; i < length; i++)
            {
                scanf("%d", &arr[i]);
            }

            int *ret = uniqueElements(arr, length);
            for (int i = 1; i < ret[0]; i++)
            {
                printf("%d ", ret[i]);
            }
            printf("\n");
            free(ret);
            free(arr);
        }
        else if (s[4] == '4')
        {
            int rows, cols;
            scanf("%d%d", &rows, &cols);
            int **matrix = (int **)malloc(rows * sizeof(int *));
            for (int i = 0; i < rows; i++)
            {
                matrix[i] = (int *)malloc(cols * sizeof(int));
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    scanf("%d", &matrix[i][j]);
                }
            }

            int **ret = transpose(matrix, rows, cols);
            for (int i = 0; i < cols; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    printf("%d ", ret[i][j]);
                }
                printf("\n");
            }

            for (int i = 0; i < cols; i++)
            {
                free(ret[i]);
            }
            free(ret);

            for (int i = 0; i < rows; i++)
            {
                free(matrix[i]);
            }
            free(matrix);
        }
        else
        {
            printf("Something is wrong with the if-else statements!\n");
        }
    }
}
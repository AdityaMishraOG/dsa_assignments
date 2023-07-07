#include "functions.h"
int main()
{
    char *s = (char *)malloc(4 * sizeof(char));
    scanf("%s", s);

    if (s[0] == 'T')
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);

        PtrNode *arr = (PtrNode *)malloc(k * sizeof(PtrNode));
        for (int i = 0; i < k; i++)
        {
            int row, col, value;
            scanf("%d%d%d", &col, &row, &value);
            arr[i] = createNode(row, col, value);
        }
        sortnodes(arr, k);
        printf("%d\n", k);
        printNodes(arr, k);

        for (int i = 0; i < k; i++)
        {
            free(arr[i]);
        }
        free(arr);
    }
    else if (s[0] == 'A')
    {
        int n, m, k1, k2;
        scanf("%d%d%d%d", &n, &m, &k1, &k2);

        PtrNode *ret = (PtrNode *)malloc((k1 + k2 + 2) * sizeof(PtrNode));

        // PtrNode *arr1 = (PtrNode *)malloc(k1 * sizeof(PtrNode));
        int ind = 0;
        for (int i = 0; i < k1; i++)
        {
            int row, col, value;
            scanf("%d%d%d", &row, &col, &value);
            // arr1[i] = createNode(row, col, value);
            ret[ind++] = createNode(row, col, value);
        }

        // printNodes(arr1, k1);
        // PtrNode *arr2 = (PtrNode *)malloc(k2 * sizeof(PtrNode));
        for (int i = 0; i < k2; i++)
        {
            int row, col, value;
            scanf("%d%d%d", &row, &col, &value);
            // arr2[i] = createNode(row, col, value);
            ret[ind++] = createNode(row, col, value);
        }
        // printNodes(arr2, k2);

        // // FREEING ARR1 AND ARR2
        // for (int i = 0; i < k1; i++)
        // {
        //     free(arr1[i]);
        // }
        // free(arr1);
        // for (int i = 0; i < k2; i++)
        // {
        //     free(arr2[i]);
        // }
        // free(arr2);
        // // ARR1 AND ARR2 HAVE BEEN FREED

        sortnodes(ret, ind);

        // printf("\n");
        // printNodes(ret, ind);
        int sub = 0;
        for (int i = 0; i < ind - 1; i++)
        {
            if ((ret[i]->row == ret[i + 1]->row) && (ret[i]->column == ret[i + 1]->column))
            {
                ret[i]->value += ret[i + 1]->value;
                if (ret[i]->value == 0)
                {
                    sub++;
                }
                ret[i + 1]->value = 0;
                i++;
                sub++;
            }
        }
        printf("%d\n", ind - sub);
        printNodes(ret, ind);
        // FREEING RET
        for (int i = 0; i < ind; i++)
        {
            free(ret[i]);
        }
        free(ret);
    }
    else if (s[0] == 'M')
    {
        int n, m, l, k1, k2;
        scanf("%d%d%d%d%d", &n, &m, &l, &k1, &k2);

        if (n == 1 && l == 1)
        {

            int arr1[m][3];
            int arr2[m][3];

            for (int i = 0; i < k1; i++)
            {
                int r, c, x;
                scanf("%d%d%d", &r, &c, &x);
                arr1[i][0] = r;
                arr1[i][1] = c;
                arr1[i][2] = x;
            }
            for (int i = 0; i < k2; i++)
            {
                int r, c, x;
                scanf("%d%d%d", &r, &c, &x);
                arr2[i][0] = r;
                arr2[i][1] = c;
                arr2[i][2] = x;
            }

            printf("1\n");
            int ans = 0;
            for (int i = 0; i < m; i++)
            {
                ans += arr1[i][2] * arr2[i][2];
            }
            printf("0 0 %d\n", ans);
            return 0;
        }

        PtrRowNode matrix1 = createMatrix(n, m, k1);
        PtrRowNode matrix2 = createTranspose(m, l, k2);
        // printf("\n");
        int finalk = 0;

        printf("%d\n", multiplycount(matrix1, matrix2));
        multiply(matrix1, matrix2);

        deleteMatrix(matrix1);
        deleteMatrix(matrix2);
    }
    else
    {
        printf("Something is wrong with the if statements!\n");
    }
    return 0;
}
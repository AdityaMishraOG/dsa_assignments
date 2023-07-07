#include "functions.h"

void reverseString(char *str, int length)
{
    if (str == NULL || length == 0)
    {
        return;
    }
    for (int i = 0; i <= (length - 1) / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    return;
}

char *compressString(char *str, int length)
{
    // ret is the array to be returned
    char *ret = (char *)malloc((2 * length + 1) * sizeof(char));
    // lor stores length or ret
    int lor = 0;
    int count = 1;
    char current_char = str[0];
    for (int i = 1; i <= length; i++)
    {
        if (str[i] == current_char)
        {
            count++;
        }
        else if (i == length)
        {
            ret[lor++] = current_char;
            // New_Implementation
            int copycount = count;
            int nod = 0;
            int sub = 1;
            int dig;
            while (copycount != 0)
            {
                copycount /= 10;
                nod++;
                sub *= 10;
            }
            sub /= 10;

            while (nod--)
            {
                int sub1 = count % sub;
                // int sub2 = count - sub1;
                dig = count / sub;
                count = count - sub * dig;
                sub /= 10;
                // printf("digit is:%d\n", dig);
                ret[lor++] = dig + 48;
            }
            break;
        }
        else if (str[i] != current_char)
        {
            ret[lor++] = current_char;
            // New_Implementation
            int copycount = count;
            int nod = 0;
            int sub = 1;
            int dig;
            while (copycount != 0)
            {
                copycount /= 10;
                nod++;
                sub *= 10;
            }
            sub /= 10;

            while (nod--)
            {
                int sub1 = count % sub;
                int sub2 = count - sub1;
                dig = count / sub;
                count = count - sub * dig;
                sub /= 10;
                // printf("digit is:%d\n", dig);
                ret[lor++] = dig + 48;
            }
            count = 1;
            current_char = str[i];
        }
    }
    // ret = (char *)realloc(ret, lor * sizeof(char));
    ret[lor] = '\0';
    return ret;
}

int *uniqueElements(int *arr, int length)
{
    int *ret = (int *)calloc(length + 1, sizeof(int));
    int lor = 1;
    int *check = (int *)calloc(10001, sizeof(int));
    for (int i = 0; i < length; i++)
    {
        if (check[arr[i]] == 0)
        {
            check[arr[i]] = 1;
            ret[lor++] = arr[i];
        }
    }
    ret[0] = lor;
    free(check);
    ret = realloc(ret, lor * sizeof(int));
    return ret;
}

int **transpose(int **matrix, int NumRow, int NumCol)
{
    int **ret = (int **)malloc(NumCol * sizeof(int *));
    for (int i = 0; i < NumCol; i++)
    {
        ret[i] = (int *)malloc(NumRow * sizeof(int));
    }
    for (int i = 0; i < NumRow; i++)
    {
        for (int j = 0; j < NumCol; j++)
        {
            ret[j][i] = matrix[i][j];
        }
    }
    return ret;
}

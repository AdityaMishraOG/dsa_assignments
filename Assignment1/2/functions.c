#include "functions.h"

// QSORT_IMPLEMNTATION
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void qsort_int(int arr[], int len)
{
    quickSort(arr, 0, len - 1);
}

// QSORT_ENDS

int *intersectionArray(int *arr1, int *arr2, int lenArr1, int lenArr2)
{
    int len;
    if (lenArr1 < lenArr2)
    {
        len = lenArr1;
    }
    else
    {
        len = lenArr2;
    }
    int *ret = (int *)malloc((len + 1) * sizeof(int));

    int i = 0, j = 0, k = 1;
    while (i != lenArr1 && j != lenArr2)
    {
        if (arr1[i] == arr2[j])
        {
            ret[k++] = arr1[i++];
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
    }
    ret[0] = k;
    return ret;
}

int countCharOccurences(const char *str, int length, char ch)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ch)
        {
            count++;
        }
    }
    return count;
}

char findFirstNonRepeatingChar(const char *str, int length)
{
    int ch = 1;
    int *arr = (int *)calloc(256, sizeof(int));
    for (int i = 0; i < length; i++)
    {
        arr[str[i]]++;
    }
    for (int i = 0; i < length; i++)
    {
        if (arr[str[i]] == 1)
        {
            ch = str[i];
            break;
        }
    }
    return ch;
}

char *findLongesetCommonPrefix(char **str, int numStr, int maxLen)
{
    char *ret = (char *)malloc(maxLen * sizeof(char));

    int i;
    for (i = 0; i < maxLen; i++)
    {
        int flag = 1;
        char ch = str[0][i];

        for (int j = 1; j < numStr; j++)
        {
            if (str[j][i] != ch)
            {
                flag = 0;
                break;
            }
            if (str[j][i] == '\0')
            {
                flag = 0;
                break;
            }
            if (j == numStr - 1)
            {
                ret[i] = ch;
            }
        }

        if (!flag)
        {
            if (i == 0)
            {
                ret[0] = '1';
                ret[1] = '\0';
                return ret;
            }
            break;
        }
    }
    // printf("ret[i] is: %c\n", ret[i]);

    ret[i] = '\0';
    return ret;
}

int *maxMin(int *arr, int lenArr)
{
    int *ret1 = (int *)calloc((lenArr + 1), sizeof(int));
    int *ret = (int *)malloc((lenArr + 1) * sizeof(int));

    int lenret = 1;
    int left_max = -5;
    for (int i = 0; i < lenArr; i++)
    {
        if (arr[i] > left_max)
        {
            left_max = arr[i];
            ret1[i]++;
        }
    }
    int right_min = __INT_MAX__;
    for (int i = lenArr - 1; i >= 0; i--)
    {
        if (arr[i] < right_min)
        {
            right_min = arr[i];
            ret1[i]++;
        }
    }
    int empty_flag = 1;
    for (int i = 0; i < lenArr; i++)
    {
        if (ret1[i] == 2)
        {
            ret[lenret++] = i;
            empty_flag = 0;
        }
    }

    ret[0] = lenret;

    // printf("ret1 is: ");
    // for (int i = 0; i < lenArr; i++)
    // {
    //     printf("%d ", ret1[i]);
    // }
    // printf("\n");

    if (empty_flag)
    {
        ret[0] = 1;
    }
    return ret;
}

char *removeSubstring(char *str, int strLength, const char *substr, int substrLength)
{
    char *ret = (char *)malloc((strLength + 1) * sizeof(char));
    int retlen = 0;
    for (int i = 0; i < strLength; i++)
    {
        int remflag = 1;
        for (int j = 0; j < substrLength; j++)
        {
            if (str[i + j] != substr[j])
            {
                remflag = 0;
                break;
            }
        }
        if (!remflag)
        {
            ret[retlen++] = str[i];
        }
        else
        {
            i += (substrLength - 1);
        }
    }
    ret[retlen] = '\0';
    if (retlen == 0)
    {
        ret = "-1";
    }
    return ret;
}

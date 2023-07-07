#include "functions.h"

void copy_array(PtrNode *A, int start, int end, PtrNode *B)
{
    for (int i = start; i < end; i++)
    {
        B[i - start]->column = A[i]->column;
        B[i - start]->row = A[i]->row;
        B[i - start]->value = A[i]->value;
        // B[i - start] = A[i];
    }
}

void merge(PtrNode *L, int sL, PtrNode *R, int sR, PtrNode *A)
{

    int l = 0, r = 0, c = 0;

    while (c <= sL + sR - 1)
    {
        if (r == sR)
        {
            A[c]->column = L[l]->column;
            A[c]->row = L[l]->row;
            A[c]->value = L[l]->value;
            c++;
            l++;
            continue;
        }

        if (l == sL)
        {
            A[c]->column = R[r]->column;
            A[c]->row = R[r]->row;
            A[c]->value = R[r]->value;
            c++;
            r++;
            continue;
        }

        if (L[l]->row < R[r]->row)
        {
            A[c]->column = L[l]->column;
            A[c]->row = L[l]->row;
            A[c]->value = L[l]->value;
            c++;
            l++;
        }
        else if (L[l]->row > R[r]->row)
        {
            A[c]->column = R[r]->column;
            A[c]->row = R[r]->row;
            A[c]->value = R[r]->value;
            c++;
            r++;
        }
        else
        {
            if (L[l]->column < R[r]->column)
            {
                A[c]->column = L[l]->column;
                A[c]->row = L[l]->row;
                A[c]->value = L[l]->value;
                c++;
                l++;
            }
            else
            {
                A[c]->column = R[r]->column;
                A[c]->row = R[r]->row;
                A[c]->value = R[r]->value;
                c++;
                r++;
            }
        }
    }
}

PtrNode createNode(int row, int col, int value)
{
    PtrNode ret = (PtrNode)malloc(sizeof(struct Node));
    ret->row = row;
    ret->column = col;
    ret->value = value;
    // ret->next = NULL;
    return ret;
}

void sortnodes(PtrNode *A, int len)
{
    if (len == 1)
    {
        return;
    }
    else
    {
        int mid = len / 2;
        // PtrNode L[mid], R[len - mid];
        PtrNode *L = (PtrNode *)malloc(mid * sizeof(struct Node));
        PtrNode *R = (PtrNode *)malloc((len - mid) * sizeof(struct Node));
        for (int i = 0; i < mid; i++)
        {
            L[i] = createNode(-1, -1, -1);
        }
        for (int i = 0; i < len - mid; i++)
        {
            R[i] = createNode(-1, -1, -1);
        }

        copy_array(A, 0, mid, L);
        copy_array(A, mid, len, R);
        sortnodes(L, mid);
        sortnodes(R, len - mid);
        merge(L, mid, R, len - mid, A);

        for (int i = 0; i < mid; i++)
        {
            free(L[i]);
        }
        for (int i = 0; i < len - mid; i++)
        {
            free(R[i]);
        }

        free(L);
        free(R);
    }
}

void printNodes(PtrNode *A, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (A[i]->value)
        {
            printf("%d %d %d\n", A[i]->row, A[i]->column, A[i]->value);
        }
    }
}

int countNonZeroNodes(PtrNode *A, int len)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (A[i]->value)
        {
            count++;
        }
    }
    return count;
}

void printAllNodes(PtrNode *A, int len)
{
    for (int i = 0; i < len; i++)
    {

        printf("%d %d %d\n", A[i]->row, A[i]->column, A[i]->value);
    }
}

// MULTIPLICATION STUFF STARTS

void copy_array_mul(int **A, int start, int end, int **B)
{
    for (int i = start; i < end; i++)
    {
        B[i - start][0] = A[i][0];
        B[i - start][1] = A[i][1];
        B[i - start][2] = A[i][2];
    }
}

void merge_mul(int **L, int sL, int **R, int sR, int **A)
{

    int l = 0, r = 0, c = 0;

    while (c <= sL + sR - 1)
    {
        if (r == sR)
        {
            A[c][0] = L[l][0];
            A[c][1] = L[l][1];
            A[c][2] = L[l][2];
            c++;
            l++;

            continue;
        }

        if (l == sL)
        {
            A[c][0] = R[r][0];
            A[c][1] = R[r][1];
            A[c][2] = R[r][2];
            c++;
            r++;
            continue;
        }

        if (L[l][0] < R[r][0])
        {
            A[c][0] = L[l][0];
            A[c][1] = L[l][1];
            A[c][2] = L[l][2];
            c++;
            l++;
        }
        else if (L[l][0] > R[r][0])
        {
            A[c][0] = R[r][0];
            A[c][1] = R[r][1];
            A[c][2] = R[r][2];
            c++;
            r++;
        }
        else
        {
            if (L[l][1] < R[r][1])
            {
                A[c][0] = L[l][0];
                A[c][1] = L[l][1];
                A[c][2] = L[l][2];
                c++;
                l++;
            }
            else if (L[l][1] >= R[r][1])
            {
                A[c][0] = R[r][0];
                A[c][1] = R[r][1];
                A[c][2] = R[r][2];
                c++;
                r++;
            }
        }
    }
}

void sort_mul(int **A, int len)
{
    if (len == 1)
    {
        return;
    }
    else
    {
        int mid = len / 2;

        int **L = (int **)malloc(mid * sizeof(int *));
        for (int i = 0; i < mid; i++)
        {
            L[i] = (int *)malloc(3 * sizeof(int));
        }
        int **R = (int **)malloc((len - mid) * sizeof(int *));
        for (int i = 0; i < (len - mid); i++)
        {
            R[i] = (int *)malloc(3 * sizeof(int));
        }

        copy_array_mul(A, 0, mid, L);
        copy_array_mul(A, mid, len, R);
        sort_mul(L, mid);
        sort_mul(R, len - mid);
        merge_mul(L, mid, R, len - mid, A);

        for (int i = 0; i < mid; i++)
        {
            free(L[i]);
        }
        free(L);
        for (int i = 0; i < (len - mid); i++)
        {
            free(R[i]);
        }
        free(R);
    }
}

PtrRowNode createRowNode(int rownumber)
{
    PtrRowNode ret = (PtrRowNode)malloc(sizeof(struct RowNode));
    ret->rownumber = rownumber;
    ret->Next = NULL;
    ret->NextRow = NULL;
    return ret;
}

PtrErectNode createErectNode(int column, int value)
{
    PtrErectNode ret = (PtrErectNode)malloc(sizeof(struct ErectNode));
    ret->value = value;
    ret->column = column;
    ret->Next = NULL;
    return ret;
}

PtrRowNode Insert(PtrRowNode currentRowNode, int row, int column, int value)
{

    if (currentRowNode->rownumber == row)
    {
        if (currentRowNode->Next == NULL)
        {
            PtrErectNode new = createErectNode(column, value);
            currentRowNode->Next = new;
        }
        else
        {
            PtrErectNode runningErect = currentRowNode->Next;
            while (runningErect->Next != NULL)
            {
                runningErect = runningErect->Next;
            }
            PtrErectNode new = createErectNode(column, value);
            runningErect->Next = new;
        }
        return currentRowNode;
    }
    else
    {
        PtrRowNode newrow = createRowNode(row);
        PtrErectNode newerect = createErectNode(column, value);
        newrow->Next = newerect;
        currentRowNode->NextRow = newrow;
        return newrow;
    }
}

PtrRowNode createMatrix(int n, int m, int k)
{
    PtrRowNode Head = createRowNode(-1);
    PtrRowNode running;
    // Head->NextRow = running;
    for (int i = 0; i < k; i++)
    {
        int row, col, value;
        scanf("%d%d%d", &row, &col, &value);

        if (i == 0)
        {
            running = createRowNode(row);
            Head->NextRow = running;
            PtrErectNode newErect = createErectNode(col, value);
            running->Next = newErect;
        }
        else
        {
            running = Insert(running, row, col, value);
        }

        // if (running->rownumber == row)
        // {
        //     if (running->Next == NULL)
        //     {
        //         PtrErectNode new = createErectNode(col, value);
        //         running->Next = new;
        //     }
        //     else
        //     {
        //         PtrErectNode runningErect = running->Next;
        //         while (runningErect->Next != NULL)
        //         {
        //             runningErect = runningErect->Next;
        //         }
        //         PtrErectNode new = createErectNode(col, value);
        //         runningErect->Next = new;
        //     }
        // }
        // else
        // {
        //     PtrRowNode newrow = createRowNode(row);
        //     PtrErectNode newerect = createErectNode(col, value);
        //     newrow->Next = newerect;
        //     running->NextRow = newrow;
        //     running = newrow;
        // }
    }
    return Head;
}

PtrRowNode createTranspose(int n, int m, int k)
{
    int **arr = (int **)malloc(k * sizeof(int *));
    for (int i = 0; i < k; i++)
    {
        arr[i] = (int *)malloc(3 * sizeof(int));
    }

    for (int i = 0; i < k; i++)
    {
        int row, col, value;
        scanf("%d%d%d", &col, &row, &value);
        arr[i][0] = row;
        arr[i][1] = col;
        arr[i][2] = value;
    }
    sort_mul(arr, k);

    PtrRowNode Head = createRowNode(-1);
    PtrRowNode running;
    for (int i = 0; i < k; i++)
    {
        // int row, col, value;
        // scanf("%d%d%d", &row, &col, &value);
        if (i == 0)
        {
            running = createRowNode(arr[i][0]);
            Head->NextRow = running;
        }

        if (running->rownumber == arr[i][0])
        {
            if (running->Next == NULL)
            {
                PtrErectNode new = createErectNode(arr[i][1], arr[i][2]);
                running->Next = new;
            }
            else
            {
                PtrErectNode runningErect = running->Next;
                while (runningErect->Next != NULL)
                {
                    runningErect = runningErect->Next;
                }
                PtrErectNode new = createErectNode(arr[i][1], arr[i][2]);
                runningErect->Next = new;
            }
        }
        else
        {
            PtrRowNode newrow = createRowNode(arr[i][0]);
            PtrErectNode newerect = createErectNode(arr[i][1], arr[i][2]);
            newrow->Next = newerect;
            running->NextRow = newrow;
            running = newrow;
        }
    }
    return Head;
}

PtrRowNode displayMatrix(PtrRowNode Head, int k)
{
    printf("%d\n", k);
    Head = Head->NextRow;
    while (Head != NULL)
    {
        PtrErectNode runningErect = Head->Next;
        while (runningErect != NULL)
        {
            printf("%d %d %d\n", Head->rownumber, runningErect->column, runningErect->value);
            runningErect = runningErect->Next;
        }
        Head = Head->NextRow;
    }
}

void deleteMatrix(PtrRowNode Head)
{

    while (Head != NULL)
    {
        PtrRowNode next = Head->NextRow;
        PtrErectNode erect = Head->Next;
        while (erect != NULL)
        {
            PtrErectNode nexterect = erect->Next;
            free(erect);
            erect = nexterect;
        }
        free(Head);
        Head = next;
    }
}

int multiplycount(PtrRowNode Head1, PtrRowNode Head2)
{
    int count = 0;
    PtrRowNode run1 = Head1->NextRow;

    while (run1 != NULL)
    {
        int finalrow = run1->rownumber;
        PtrRowNode run2 = Head2->NextRow;

        while (run2 != NULL)
        {
            int finalvalue = 0;
            int finalcol = run2->rownumber;
            PtrErectNode runningErect1 = run1->Next;
            PtrErectNode runningErect2 = run2->Next;
            while (runningErect2 != NULL && runningErect1 != NULL)
            {
                if (runningErect1->column == runningErect2->column)
                {
                    finalvalue += runningErect1->value * runningErect2->value;
                    // printf("%d %d %d\n", finalrow, finalcol, finalvalue);
                    runningErect1 = runningErect1->Next;
                    runningErect2 = runningErect2->Next;
                }
                else if (runningErect1->column > runningErect2->column)
                {
                    runningErect2 = runningErect2->Next;
                }
                else
                {
                    runningErect1 = runningErect1->Next;
                }
            }
            if (finalvalue)
            {
                count++;
            }
            run2 = run2->NextRow;
        }
        run1 = run1->NextRow;
    }
    return count;
}

void multiply(PtrRowNode Head1, PtrRowNode Head2)
{
    // PtrRowNode ret = createRowNode(-1);
    // PtrRowNode runningret;
    // int retindex = 0;

    PtrRowNode run1 = Head1->NextRow;

    while (run1 != NULL)
    {
        int finalrow = run1->rownumber;
        PtrRowNode run2 = Head2->NextRow;

        while (run2 != NULL)
        {
            int finalvalue = 0;
            int finalcol = run2->rownumber;
            PtrErectNode runningErect1 = run1->Next;
            PtrErectNode runningErect2 = run2->Next;
            while (runningErect2 != NULL && runningErect1 != NULL)
            {
                if (runningErect1->column == runningErect2->column)
                {
                    finalvalue += runningErect1->value * runningErect2->value;
                    // printf("%d %d %d\n", finalrow, finalcol, finalvalue);
                    runningErect1 = runningErect1->Next;
                    runningErect2 = runningErect2->Next;
                }
                else if (runningErect1->column > runningErect2->column)
                {
                    runningErect2 = runningErect2->Next;
                }
                else
                {
                    runningErect1 = runningErect1->Next;
                }
            }
            if (finalvalue)
            {
                printf("%d %d %d\n", finalrow, finalcol, finalvalue);
            }
            run2 = run2->NextRow;
        }
        run1 = run1->NextRow;
    }
    // return ret;
}

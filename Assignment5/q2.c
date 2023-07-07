#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

short int xcoordinate[] = {0, 1, 0, -1}, matrix[1002][1002];
short int ycoordinate[] = {1, 0, -1, 0}, n, m;
int Distance[1002][1002];

typedef struct PairSt *Pair;
struct PairSt
{
    short int first;
    short int second;
};

Pair CreatePair(short int i, short int j)
{
    Pair ret = (Pair)malloc(sizeof(struct PairSt));
    ret->first = i;
    ret->second = j;
    return ret;
}
/*
void Prshort intPair(Pair P)
{
    prshort intf("(%hd, %hd) ", P->first, P->second);
}
*/
typedef struct CircularDequeNode *Deque;
typedef struct CircularDequeNode *PtrDequeNode;
struct CircularDequeNode
{
    Pair value;
    PtrDequeNode next;
    PtrDequeNode prev;
};

Deque createNode(Pair val)
{
    Deque ret = (Deque)malloc(sizeof(struct CircularDequeNode));
    ret->value = val;
    ret->next = NULL;
    ret->prev = NULL;
    return ret;
}

void Push(Deque head, Pair val)
{
    Deque new = createNode(val);
    if (head->next == NULL)
    {
        head->next = new;
        new->next = new;
        new->prev = new;
        return;
    }

    Deque first = head->next;
    Deque last = first->prev;

    last->next = new;
    new->next = first;
    first->prev = new;
    new->prev = last;
}

Pair Pop(Deque head)
{
    if (head->next == NULL)
    {
        return CreatePair(-1, -1);
    }
    Deque first = head->next;
    if (first->next == first)
    {
        Pair ret = first->value;
        // free(first);
        head->next = NULL;
        return ret;
    }

    Deque second = first->next;
    Deque last = first->prev;
    Pair ret = first->value;

    last->next = second;
    second->prev = last;
    // free(first);
    head->next = second;

    return ret;
}

void Inject(Deque head, Pair val)
{

    Deque new = createNode(val);
    if (head->next == NULL)
    {
        head->next = new;
        new->next = new;
        new->prev = new;
        return;
    }

    Deque first = head->next;
    Deque last = first->prev;

    last->next = new;
    new->next = first;
    first->prev = new;
    new->prev = last;

    head->next = new;
}

Pair popRear(Deque head)
{
    if (head->next == NULL)
    {
        return CreatePair(SHRT_MIN, SHRT_MIN);
    }
    Deque first = head->next;
    if (first->next == first)
    {
        Pair ret = first->value;
        // free(first);
        head->next = NULL;
        return ret;
    }
    Deque last = first->prev;
    Deque secondlast = last->prev;
    Pair ret = last->value;

    secondlast->next = first;
    first->prev = secondlast;
    // free(last);

    return ret;
}

/*
short int **Create2D()
{

    short int **ret = (short int **)malloc((n + 1) * sizeof(short int *));
    for (short int i = 0; i < n + 1; i++)
    {
        ret[i] = (short int *)malloc((m + 1) * sizeof(short int));
    }

    for (short int i = 1; i < n + 1; i++)
    {
        for (short int j = 1; j < m + 1; j++)
        {
            short int x;
            scanf("%hd", &x);
            ret[i][j] = x;
        }
    }
    return ret;
}

short int **Create2DDistance()
{
    short int **ret = (short int **)malloc((n + 1) * sizeof(short int *));
    for (short int i = 0; i < n + 1; i++)
    {
        ret[i] = (short int *)malloc((m + 1) * sizeof(short int));
        for (short int j = 0; j < m + 1; j++)
        {
            ret[i][j] = SHRT_MAX;
        }
    }
    return ret;
}
*/
short int Travis(Pair u)
{
    Deque Q = createNode(CreatePair(-1, -1));
    Distance[u->first][u->second] = 0;
    Push(Q, u);
    // short int Count = 0;
    while (Q->next != NULL)
    {
        Pair v = Pop(Q);
        short int i = v->first;
        short int j = v->second;

        // PUT A CONDITION WHICH

        // Prshort intPair(v);
        // prshort intf("\n");
        // if (i == n && j == m)
        // {
        //   break;
        // }
        // free(v);

        for (short int index = 0; index < 4; index++)
        {
            // prshort intf("Q->");
            // Prshort int(Q);
            // prshort intf("while loop....\n");
            short int idash = i + xcoordinate[index];
            short int jdash = j + ycoordinate[index];

            if (idash >= 1 && idash <= n && jdash >= 1 && jdash <= m)
            {

                short int Weight;
                if (matrix[i][j] == matrix[idash][jdash])
                {
                    Weight = 0;
                }
                else
                {
                    Weight = 1;
                }

                if (Distance[idash][jdash] > Distance[i][j] + Weight)
                {
                    Distance[idash][jdash] = Distance[i][j] + Weight;

                    Pair new = CreatePair(idash, jdash);

                    // Count++;
                    // prshort intf("inserting....\n");
                    if (Weight == 1)
                    {
                        Push(Q, new);
                    }
                    else
                    {
                        Inject(Q, new);
                    }
                }
            }
        }
        // prshort intf("End of while loop....\n");
    }
    /*
    for (short int i = 0; i < n + 1; i++)
    {
        for (short int j = 0; j < m + 1; j++)
        {
            prshort intf("%hd ", Distance[i][j]);
        }
        prshort intf("\n");
    }
    */

    short int ret = Distance[n][m];
    /*
    for (short int i = 0; i < n + 1; i++)
    {
        free(Distance[i]);
    }
    free(Distance);
    */
    // free(Q);

    // prshort intf("Adding to the Queue %hd times\n", Count);
    return ret;
}

short int main()
{
    short int t;
    scanf("%hd", &t);

    while (t--)
    {
        scanf("%hd%hd", &n, &m);

        for (short int i = 1; i < n + 1; i++)
        {

            for (short int j = 1; j < m + 1; j++)
            {
                short int x;
                scanf("%hd", &x);
                matrix[i][j] = x;
                Distance[i][j] = 1000003;
            }
        }

        // short int matrix[n + 1][m + 1];
        // short int Distance[n + 1][m + 1];

        short int Answer = Travis(CreatePair(1, 1));
        printf("%hd\n", Answer);

        /*
        for (short int i = 0; i < n + 1; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
        */
    }

    return 0;
}
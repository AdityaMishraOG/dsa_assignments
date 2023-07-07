#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

int xcoordinate[] = {1, 0, -1, 0, -1, 1, 1, -1};
int ycoordinate[] = {0, -1, 0, 1, 1, 1, -1, -1};

typedef struct PairSt *Pair;
struct PairSt
{
    int first;
    int second;
};

Pair CreatePair(int i, int j)
{
    Pair ret = (Pair)malloc(sizeof(struct PairSt));
    ret->first = i;
    ret->second = j;
    return ret;
}

typedef struct PriorityQueueSt *PriorityQueue;
struct PriorityQueueSt
{
    int capacity;
    int size;
    Pair *arr;
};

int isEmpty(PriorityQueue h)
{
    if (h->size == 0)
    {
        return 1;
    }
    return 0;
}

int isFull(PriorityQueue h)
{
    if (h->size + 1 == h->capacity)
    {
        return 1;
    }
    return 0;
}

PriorityQueue createPriorityQueue(int capacity)
{
    PriorityQueue ret = (PriorityQueue)malloc(sizeof(struct PriorityQueueSt));
    assert(ret != NULL);
    ret->capacity = 1 + capacity;
    ret->arr = (Pair *)malloc((1 + capacity) * sizeof(Pair));
    assert(ret->arr != NULL);
    // assert(dominance)
    for (int i = 0; i < ret->capacity + 1; i++)
    {
        ret->arr[0] = (Pair)malloc(sizeof(struct PairSt));
    }

    ret->arr[0]->first = 0;
    ret->arr[0]->second = 0;
    ret->size = 0;
    return ret;
}

void insertIntoPriorityQueue(Pair value, PriorityQueue h, int **Distance)
{
    // printf("yo\n");
    if (isFull(h))
    {
        fprintf(stderr, "PriorityQueue is already full!");
        return;
    }
    // printf("size = %d\n", h->size);
    // printf("value -> %d %d\n", value->first, value->second);
    // printf("Distance[value] = %d\n", Distance[value->first][value->second]);
    int i;
    // printf("i = %d\n", h->size + 1);
    for (i = ++h->size; Distance[h->arr[i / 2]->first][h->arr[i / 2]->second] > Distance[value->first][value->second]; i /= 2)
    {
        // printf("i=%d\n", i);
        // printf("Distance[i/2] = %d\n", Distance[h->arr[i / 2]->first][h->arr[i / 2]->second]);

        /*if (i == 0)
        {
            printf("i = 0\n");
            // break;
        }*/
        // printf("i is %d\n", i);
        h->arr[i] = h->arr[i / 2];
    }
    h->arr[i] = value;
    // printf("i = %d %d %d\n", i, h->arr[i]->first, h->arr[i]->second);
    // printf("size = %d\n\n", h->size);
    return;
}

Pair extractMin(PriorityQueue h, int **Distance)
{
    if (isEmpty(h))
    {
        fprintf(stderr, "PriorityQueue is already empty!");
        return CreatePair(INT_MIN, INT_MIN);
    }
    int i;
    Pair minElement, last;

    minElement = h->arr[1];
    last = h->arr[h->size--];

    int child;
    for (i = 1; i * 2 <= h->size; i = child)
    {
        child = 2 * i;
        if ((child != h->size) && (Distance[h->arr[child + 1]->first][h->arr[child + 1]->second] < Distance[h->arr[child]->first][h->arr[child]->second]))
        {
            child++;
        }
        ///////////////////////////////////////////
        // CHECK IF LAST NEEDS TO PERCOLATE DOWN //
        // IN WHICH CASE, CHILD NEEDS TO MOVE UP //
        // OR WE FIND THE PLACE TO INSERT LAST   //
        ///////////////////////////////////////////
        if (Distance[last->first][last->second] > Distance[h->arr[child]->first][h->arr[child]->second])
        {
            h->arr[i] = h->arr[child];
        }
        /*
        else if (Distance[last->first][last->second] > Distance[h->arr[child]->first][h->arr[child]->second])
        {
            if (last->first > h->arr[child]->first)
            {
                h->arr[i] = h->arr[child];
            }
            else if (last->first == h->arr[child]->first)
            {
                if (last->second > h->arr[child]->second)
                {
                    h->arr[i] = h->arr[child];
                }
            }
        }
        */
        else
        {
            break;
        }
    }
    h->arr[i] = last;
    return minElement;
}

int MinimumValue(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int **Create2D(int n, int m)
{
    int **ret = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
    {
        ret[i] = (int *)malloc((m + 1) * sizeof(int));
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            int x;
            scanf("%d", &x);
            ret[i][j] = x;
        }
    }
    return ret;
}
int **Create2DVisited(int n, int m)
{
    int **ret = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
    {
        ret[i] = (int *)calloc((m + 1), sizeof(int));
    }
    return ret;
}

// Only MAGA Hat Lovers can understand the true value of building a wall
int DonaldTrump(int n, int m, int **Matrix)
{
    // printf("yo\n");
    int **Distance = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
    {
        Distance[i] = (int *)malloc((m + 1) * sizeof(int));
        for (int j = 0; j < m + 1; j++)
        {
            Distance[i][j] = INT_MAX;
        }
    }
    Distance[0][0] = INT_MIN;

    PriorityQueue pq = createPriorityQueue(n * m * 2);
    int i = 1;
    for (int j = 1; j < m + 1; j++)
    {
        // printf("inserting... i,j = %d, %d\n", i, j);
        Distance[i][j] = Matrix[i][j];
        insertIntoPriorityQueue(CreatePair(i, j), pq, Distance);
        // printf("inserted\n");
    }
    int j = m;
    for (int i = 1; i < n + 1; i++)
    {
        // printf("inserting...\n");
        Distance[i][j] = Matrix[i][j];
        insertIntoPriorityQueue(CreatePair(i, j), pq, Distance);
    }

    // printf("starting pq...\n");
    while (!isEmpty(pq))
    {
        Pair p = extractMin(pq, Distance);

        // printf("p = %d, %d\n", p->first, p->second);
        for (int index = 0; index < 8; index++)
        {
            int idash = p->first + xcoordinate[index];
            int jdash = p->second + ycoordinate[index];

            if (idash >= 1 && idash <= n && jdash >= 1 && jdash <= m)
            {
                if (Distance[idash][jdash] > Distance[p->first][p->second] + Matrix[idash][jdash])
                {
                    Distance[idash][jdash] = Distance[p->first][p->second] + Matrix[idash][jdash];
                    insertIntoPriorityQueue(CreatePair(idash, jdash), pq, Distance);
                }
            }
        }
    }

    int ret = INT_MAX;
    j = 1;
    for (int i = 1; i < n + 1; i++)
    {
        ret = MinimumValue(ret, Distance[i][j]);
    }
    i = n;
    for (int j = 1; j < m + 1; j++)
    {
        ret = MinimumValue(ret, Distance[i][j]);
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int **Matrix = Create2D(n, m);

        if (Matrix[1][1] == 1 || Matrix[n][m] == 1)
        {
            printf("1\n");
            continue;
        }

        int ret = DonaldTrump(n, m, Matrix);
        printf("%d\n", ret);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef struct PriorityQueueSt *PriorityQueue;
struct PriorityQueueSt
{
    int capacity;
    int size;
    int *arr;
};

int IsEmpty(PriorityQueue h)
{
    if (h->size == 0)
    {
        return 1;
    }
    return 0;
}

int IsFull(PriorityQueue h)
{
    if (h->size + 1 == h->capacity)
    {
        return 1;
    }
    return 0;
}

PriorityQueue CreatePriorityQueue(int capacity)
{
    PriorityQueue ret = (PriorityQueue)malloc(sizeof(struct PriorityQueueSt));
    assert(ret != NULL);
    ret->capacity = 1 + capacity;
    ret->arr = (int *)malloc((1 + capacity) * sizeof(int));
    assert(ret->arr != NULL);
    // assert(dominance)
    ret->arr[0] = INT_MIN;
    ret->size = 0;
    return ret;
}

void InsertIntoPriorityQueue(int value, PriorityQueue h)
{
    if (IsFull(h))
    {
        fprintf(stderr, "PriorityQueue is already full!");
        return;
    }

    int i;
    for (i = ++h->size; h->arr[i / 2] > value; i /= 2)
    {
        h->arr[i] = h->arr[i / 2];
    }
    h->arr[i] = value;
    return;
}

int ExtractMin(PriorityQueue h)
{
    if (IsEmpty(h))
    {
        fprintf(stderr, "PriorityQueue is already empty!");
        return INT_MIN;
    }
    int i;
    int minElement, last;

    minElement = h->arr[1];
    last = h->arr[h->size--];

    int child;
    for (i = 1; i * 2 <= h->size; i = child)
    {
        child = 2 * i;
        if ((child != h->size) && (h->arr[child + 1] < h->arr[child]))
        {
            child++;
        }
        ///////////////////////////////////////////
        // CHECK IF LAST NEEDS TO PERCOLATE DOWN //
        // IN WHICH CASE, CHILD NEEDS TO MOVE UP //
        // OR WE FIND THE PLACE TO INSERT LAST   //
        ///////////////////////////////////////////
        if (last > h->arr[child])
        {
            h->arr[i] = h->arr[child];
        }
        else
        {
            break;
        }
    }
    h->arr[i] = last;
    return minElement;
}

typedef struct AdjacencyNode *PtrAdjacencyNode;
typedef PtrAdjacencyNode *PtrAdjacencyList;
struct AdjacencyNode
{
    int value;
    PtrAdjacencyNode next;
};

PtrAdjacencyNode CreateAdjacencyNode(int value)
{
    PtrAdjacencyNode ret = (PtrAdjacencyNode)malloc(sizeof(struct AdjacencyNode));
    ret->next = NULL;
    ret->value = value;
    return ret;
}

void Insert(PtrAdjacencyNode AdjNode, int value)
{

    PtrAdjacencyNode new = (PtrAdjacencyNode)malloc(sizeof(struct AdjacencyNode));
    new->value = value;
    new->next = AdjNode->next;
    AdjNode->next = new;
}

PtrAdjacencyList CreateAdjacencyList(int n, int m)
{
    PtrAdjacencyNode *ret = (PtrAdjacencyNode *)malloc((n + 1) * sizeof(PtrAdjacencyNode));
    for (int i = 1; i < n + 1; i++)
    {
        ret[i] = CreateAdjacencyNode(-1);
    }
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        Insert(ret[x], y);
        Insert(ret[y], x);
    }
    return ret;
}

void PrintAdjacencyList(int n, PtrAdjacencyList adj)
{
    for (int i = 1; i < n + 1; i++)
    {
        printf("%d -> ", i);
        PtrAdjacencyNode cur = adj[i];
        cur = cur->next;
        while (cur != NULL)
        {
            printf("%d ", cur->value);
            cur = cur->next;
        }
        printf("\n");
    }
}

void BreadthFirstSearch(int i, int n, PtrAdjacencyList adj)
{
    PriorityQueue Queue = CreatePriorityQueue(n);
    InsertIntoPriorityQueue(i, Queue);

    int *Visited = (int *)calloc(n + 1, sizeof(int));
    Visited[i] = 1;
    while (!IsEmpty(Queue))
    {
        int val = ExtractMin(Queue);
        printf("%d ", val);
        PtrAdjacencyNode cur = adj[val];
        cur = cur->next;

        while (cur != NULL)
        {
            if (!Visited[cur->value])
            {
                InsertIntoPriorityQueue(cur->value, Queue);
                Visited[cur->value] = 1;
            }
            cur = cur->next;
        }
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    PtrAdjacencyList adj = CreateAdjacencyList(n, m);
    // PrintAdjacencyList(n, adj);

    BreadthFirstSearch(1, n, adj);
    return 0;
}
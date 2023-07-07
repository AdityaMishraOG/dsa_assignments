#include <stdio.h>
#include <stdlib.h>

typedef struct Node *tree;
struct Node
{
    int value;
    tree left;
    tree right;
};

typedef struct queueNode *queue;
struct queueNode
{
    tree tnode;
    queue next;
    queue prev;
};

// QUEUE IMPLEMENTATION BEGINS
queue createqueue(tree tnode)
{
    queue ret = (queue)malloc(sizeof(struct Node));
    ret->tnode = tnode;
    ret->next = NULL;
    ret->prev = NULL;
    return ret;
}

void Push(queue head, tree tnode)
{
    queue new1 = createqueue(tnode);
    if (head->next == NULL)
    {
        head->next = new1;
        new1->next = new1;
        new1->prev = new1;
        return;
    }

    queue first = head->next;
    queue last = first->prev;

    last->next = new1;
    new1->next = first;
    first->prev = new1;
    new1->prev = last;
}

tree Pop(queue head)
{
    if (head->next == NULL)
    {
        return NULL;
    }
    queue first = head->next;
    if (first->next == first)
    {
        tree ret = first->tnode;
        // free(first);
        head->next = NULL;
        return ret;
    }

    queue second = first->next;
    queue last = first->prev;
    tree ret = first->tnode;

    last->next = second;
    second->prev = last;
    // free(first);
    head->next = second;

    return ret;
}

void Print(queue head)
{
    if (head->next == NULL)
    {
        printf("-1\n");
        return;
    }
    queue first = head->next;
    queue running = head->next;
    printf("%d ", running->tnode->value);
    running = running->next;
    while (running != first)
    {
        printf("%d ", running->tnode->value);
        running = running->next;
    }
    printf("\n");
}

tree popRear(queue head)
{
    if (head->next == NULL)
    {
        return NULL;
    }
    queue first = head->next;
    if (first->next == first)
    {
        tree ret = first->tnode;
        // free(first);
        head->next = NULL;
        return ret;
    }
    queue last = first->prev;
    queue secondlast = last->prev;
    tree ret = last->tnode;

    secondlast->next = first;
    first->prev = secondlast;
    // free(last);

    return ret;
}

// QUEUE IMPLEMENTATION ENDS

int *createArray(int n)
{
    int *ret = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ret[i]);
    }
    return ret;
}

tree createNode(int val)
{
    tree ret = (tree)malloc(sizeof(struct Node));
    ret->value = val;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}
// START IS
tree createTreeFromArrays(int si, int ei, int *inarr, int sp, int ep, int *prearr)
{
    // printf("si = %d\n", si);
    // printf("ei = %d\n", ei);
    // printf("sp = %d\n", sp);
    // printf("ep = %d\n", ep);
    // printf("\n");
    if (ei - si != ep - sp)
    {
        // printf("ERROR!\n");
    }
    if (si > ei || sp > ep)
    {
        return NULL;
    }
    if (si == ei)
    {
        return createNode(inarr[si]);
    }
    if (sp == ep)
    {
        return createNode(prearr[sp]);
    }
    tree head = createNode(prearr[sp]);

    int mid = si;
    while (prearr[sp] != inarr[mid])
    {
        mid++;
    }
    // printf("mid = %d\n\n", mid);
    head->left = createTreeFromArrays(si, mid - 1, inarr, sp + 1, mid + sp - si, prearr);
    head->right = createTreeFromArrays(mid + 1, ei, inarr, mid + 1 + ep - ei, ep, prearr);
    return head;
}

void levelorder(tree thead)
{
    if (thead == NULL)
    {
        return;
    }

    queue qhead = createqueue(NULL);
    Push(qhead, thead);

    while (qhead->next != NULL)
    {
        tree popped_tnode = Pop(qhead);

        // processing starts

        printf("%d ", popped_tnode->value);

        // processing ends

        if (popped_tnode->left != NULL)
        {
            Push(qhead, popped_tnode->left);
        }
        if (popped_tnode->right != NULL)
        {
            Push(qhead, popped_tnode->right);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int *inarr = createArray(n);
        int *prearr = createArray(n);
        tree head = createTreeFromArrays(0, n - 1, inarr, 0, n - 1, prearr);
        levelorder(head);
        printf("\n");
    }

    return 0;
}
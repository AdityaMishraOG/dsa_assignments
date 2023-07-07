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
tree createNode(int val)
{
    tree ret = (tree)malloc(sizeof(struct Node));
    ret->value = val;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

tree insert(tree head, int val)
{
    if (head == NULL)
    {
        return createNode(val);
    }
    else if (head->value > val)
    {
        head->left = insert(head->left, val);
    }
    else if (head->value < val)
    {
        head->right = insert(head->right, val);
    }

    return head;
}

tree ListToBST(int *arr)
{
    tree head = NULL;
    int i = 1;

    for (int i = 0; i < arr[0]; i++)
    {
        head = insert(head, arr[i + 1]);
    }

    return head;
}
tree f(tree head, int *ptrtosum)
{
    head->value = head->value + *ptrtosum;
    *ptrtosum = head->value;
    return head;
}

void change(tree head, int *ptrtosum)
{
    if (head != NULL)
    {
        change(head->left, ptrtosum);
        head = f(head, ptrtosum);
        change(head->right, ptrtosum);
    }
}

void ModifyBST(tree head)
{
    int *ptrtosum = (int *)calloc(1, sizeof(int));

    change(head, ptrtosum);
}
void levelorder(tree thead, int *sum)
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
        *sum += popped_tnode->value;

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
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc((n + 1) * sizeof(int));
    arr[0] = n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[1 + i]);
    }

    tree head = ListToBST(arr);

    ModifyBST(head);

    int *sum = (int *)calloc(1, sizeof(int));
    levelorder(head, sum);
    printf("\n");

    printf("%d\n", *sum);

    return 0;
}
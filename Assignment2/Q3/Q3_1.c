#include <stdio.h>
#include <stdlib.h>

typedef struct Node *tree;
struct Node
{
    int value;
    tree left;
    tree right;
    int level;
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

tree createNode(int val, int level)
{
    tree ret = (tree)malloc(sizeof(struct Node));
    ret->value = val;
    ret->left = NULL;
    ret->right = NULL;
    ret->level = level;
    return ret;
}

tree insert(tree head, int val, int level)
{
    if (head == NULL)
    {
        return createNode(val, level);
    }
    else if (head->value > val)
    {
        head->left = insert(head->left, val, level + 1);
    }
    else if (head->value < val)
    {
        head->right = insert(head->right, val, level + 1);
    }

    return head;
}

// void inorder(tree thead)
// {
//     if (thead != NULL)
//     {
//         inorder(thead->left);
//         printf("value: %d\t level: %d\n", thead->value, thead->level);
//         inorder(thead->right);
//     }
// }

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

void zigzagorder(tree thead)
{
    if (thead == NULL)
    {
        return;
    }
    // queue retqhead = createqueue(NULL);
    queue qhead = createqueue(NULL);

    // int evenrow = 1;
    // int nextevenrow;
    Push(qhead, thead);

    queue otherqhead = createqueue(NULL);
    otherqhead->next = NULL;
    int level = 0;
    // int prevlevel;

    // WE STORE EVEN LEVELS IN qhead
    // WE STORE ODD LEVELS IN otherqhead
    while (qhead->next != NULL || otherqhead->next != NULL)
    {
        ;
        if (level % 2 == 0) // EVEN LEVEL 0, 2, 4,...
        {
            while (qhead->next != NULL)
            {
                tree current = popRear(qhead);

                printf("%d ", current->value);
                if (current->left != NULL)
                {
                    Push(otherqhead, current->left);
                }
                if (current->right != NULL)
                {
                    Push(otherqhead, current->right);
                }
            }
            level++;
            // printf("\n");
        }
        else if (level % 2 == 1) // ODD LEVEL 1, 3, 5, ...
        {
            while (otherqhead->next != NULL)
            {
                tree current = popRear(otherqhead);
                printf("%d ", current->value);

                if (current->right != NULL)
                {
                    Push(qhead, current->right);
                }
                if (current->left != NULL)
                {
                    Push(qhead, current->left);
                }
            }
            level++;
            // printf("\n");
        }

        // prevlevel = level;
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        tree head = NULL;

        int n;
        scanf("%d", &n);
        int n_copy = n;
        while (n_copy--)
        {
            int x;
            scanf("%d", &x);
            head = insert(head, x, 0);
        }

        // printf("The inorder traversal of the tree is: \n");
        // inorder(head);
        // printf("\n");

        // printf("The level zigzag traversal of the tree is: \n");
        zigzagorder(head);
        printf("\n");
    }

    return 0;
}
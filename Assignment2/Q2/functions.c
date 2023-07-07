#include "functions.h"

Queue createNode(int val)
{
    Queue ret = (Queue)malloc(sizeof(struct Node));
    ret->value = val;
    ret->next = NULL;
    ret->prev = NULL;
    return ret;
}

void Push(Queue head, int val)
{
    Queue new = createNode(val);
    if (head->next == NULL)
    {
        head->next = new;
        new->next = new;
        new->prev = new;
        return;
    }

    Queue first = head->next;
    Queue last = first->prev;

    last->next = new;
    new->next = first;
    first->prev = new;
    new->prev = last;
}

int Pop(Queue head)
{
    if (head->next == NULL)
    {
        return -1;
    }
    Queue first = head->next;
    if (first->next == first)
    {
        int ret = first->value;
        // free(first);
        head->next = NULL;
        return ret;
    }

    Queue second = first->next;
    Queue last = first->prev;
    int ret = first->value;

    last->next = second;
    second->prev = last;
    // free(first);
    head->next = second;

    return ret;
}

void Inject(Queue head, int val)
{

    Queue new = createNode(val);
    if (head->next == NULL)
    {
        head->next = new;
        new->next = new;
        new->prev = new;
        return;
    }

    Queue first = head->next;
    Queue last = first->prev;

    last->next = new;
    new->next = first;
    first->prev = new;
    new->prev = last;

    head->next = new;
}

int popRear(Queue head)
{
    if (head->next == NULL)
    {
        return -1;
    }
    Queue first = head->next;
    if (first->next == first)
    {
        int ret = first->value;
        // free(first);
        head->next = NULL;
        return ret;
    }
    Queue last = first->prev;
    Queue secondlast = last->prev;
    int ret = last->value;

    secondlast->next = first;
    first->prev = secondlast;
    // free(last);

    return ret;
}

void Print(Queue head)
{
    if (head->next == NULL)
    {
        printf("-1\n");
        return;
    }
    Queue first = head->next;
    Queue running = head->next;
    printf("%d ", running->value);
    running = running->next;
    while (running != first)
    {
        printf("%d ", running->value);
        running = running->next;
    }
    printf("\n");
}

void PrintReverse(Queue head)
{
    if (head->next == NULL)
    {
        printf("-1\n");
        return;
    }

    Queue first = head->next;
    Queue last = first->prev;
    Queue running = last;
    printf("%d ", running->value);
    running = running->prev;
    while (running != last)
    {
        printf("%d ", running->value);
        running = running->prev;
    }
    printf("\n");
}

int findElem(Queue head, int pos)
{
    // USING ZERO INDEXING
    pos--;
    if (head->next == NULL)
    {
        return -1;
    }

    Queue first = head->next;
    Queue running = first;
    if (pos == 0)
    {
        return first->value;
    }
    running = running->next;
    pos--;
    while (pos != 0 && running != first)
    {
        running = running->next;
        pos--;
    }
    if (running == first)
    {
        return -1;
    }
    return running->value;
}

void removeKElems(Queue head, int k)
{
    if (head->next == NULL)
    {
        return;
    }

    Queue first = head->next;
    Queue last = first->prev;
    if (first == last)
    {
        head->next = NULL;
        return;
    }
    while (k != 0 && first != last->next)
    {
        first = first->next;
        k--;
    }
    if (first == last->next)
    {
        head->next = NULL;
        return;
    }
    last->next = first;
    first->prev = last;
    head->next = first;
}

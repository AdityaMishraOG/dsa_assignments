#include "functions.h"

int IsFull(Stack S)
{
    if (S->MaxCapacity == S->TopIndex + 1)
    {
        return 1;
    }
    return 0;
}

int IsEmpty(Stack S)
{
    if (S->TopIndex == -1)
    {
        return 1;
    }
    return 0;
}

int Push(Stack S, char ch)
{
    if (IsFull(S))
    {
        return 0;
    }
    S->Elements[++S->TopIndex] = ch;
    return 1;
}

char Pop(Stack S)
{
    if (IsEmpty(S))
    {
        return '-';
    }
    char ch = S->Elements[S->TopIndex];
    S->TopIndex--;
    return ch;
}

char Top(Stack S)
{
    if (IsEmpty(S))
    {
        return '-';
    }
    return S->Elements[S->TopIndex];
}

Stack CreateStack(int MaxCapacity)
{
    Stack ret = (Stack)malloc(sizeof(struct StackStructure));
    ret->Elements = (char *)malloc(MaxCapacity * sizeof(char));
    ret->MaxCapacity = MaxCapacity;
    ret->TopIndex = -1;
    return ret;
}

int Balanced(char *str, int len)
{
    Stack S = CreateStack(len);
    int brackets_count = 0;
    for (int i = 0; i < len; i++)
    {
        // PUSH
        if (str[i] == '(')
        {
            Push(S, '(');
            brackets_count++;
        }
        else if (str[i] == '{')
        {
            Push(S, '{');
            brackets_count++;
        }
        else if (str[i] == '[')
        {
            Push(S, '[');
            brackets_count++;
        }
        // POP
        else if (str[i] == ')')
        {
            char ch = Pop(S);
            brackets_count++;
            if (ch != '(')
            {
                return 0;
            }
        }
        else if (str[i] == '}')
        {
            char ch = Pop(S);
            brackets_count++;
            if (ch != '{')
            {
                return 0;
            }
        }
        else if (str[i] == ']')
        {
            char ch = Pop(S);
            brackets_count++;
            if (ch != '[')
            {
                return 0;
            }
        }
    }
    if (!brackets_count)
    {
        return 0;
    }
    if (IsEmpty(S))
    {
        return 1;
    }
    return 0;
}

int Palindrome(char *str, int len)
{
    Stack S = CreateStack(len);
    for (int i = 0; i < len; i++)
    {

        // IF LENGTH IS ODD THEN IGNORE THE MIDDLE CHARACTER
        if (len % 2 && i == (len - 1) / 2)
        {
            // printf("i is: %d\n", i);
            // printf("Executing continue...\n");
            continue;
        }
        // FOR THE FIRST HALF OF THE STRING, PUSH THE ELEMENTS
        else if (i < len / 2)
        {
            Push(S, str[i]);
        }
        else
        {
            char ch = Pop(S);
            // printf("char ch is: %c\n", ch);
            // printf("str[i] is: %c\n", str[i]);
            // printf("i is: %d\n\n", i);
            if (ch != str[i])
            {
                return 0;
            }
        }
    }
    if (IsEmpty(S))
    {
        return 1;
    }
    return 0;
}

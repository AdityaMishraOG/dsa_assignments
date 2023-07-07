#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);

    char ch;
    scanf("%c", &ch);

    Queue head = createNode(-1);

    while (t--)
    {
        char *s = (char *)malloc(6 * sizeof(char));
        scanf("%s", s);
        // printf("%s", s);

        if (s[4] == '1')
        {
            int n;
            scanf("%d", &n);
            Push(head, n);
        }
        else if (s[4] == '2')
        {
            int rem = Pop(head);
            printf("%d\n", rem);
        }
        else if (s[4] == '3')
        {
            int n;
            scanf("%d", &n);
            Inject(head, n);
        }
        else if (s[4] == '4')
        {
            int rem = popRear(head);

            printf("%d\n", rem);
        }
        else if (s[4] == '5')
        {
            Print(head);
        }
        else if (s[4] == '6')
        {
            PrintReverse(head);
        }
        else if (s[4] == '7')
        {
            int pos;
            scanf("%d", &pos);
            int ret = findElem(head, pos);
            printf("%d\n", ret);
        }
        else if (s[4] == '8')
        {
            int k;
            scanf("%d", &k);
            removeKElems(head, k);
        }
        else
        {
            printf("Something is wrong with the if-else statements!\n");
        }
    }
}
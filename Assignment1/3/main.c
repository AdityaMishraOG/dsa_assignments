#include "functions.h"

int main()
{
    int t;
    scanf("%d", &t);
    // char remve;
    // scanf("%c", &remve);
    getchar();
    PtrNode head = createNode(0);
    while (t--)
    {
        char *s = (char *)malloc(6 * sizeof(char));
        scanf("%s", s);
        // INSERT
        if (s[4] == '1')
        {
            int n;
            scanf("%d", &n);
            Insert(head, n);
        }
        // FIND
        else if (s[4] == '2')
        {
            int n;
            scanf("%d", &n);
            // if (Find(head, n) != NULL)
            // {
            //     head = Find(head, n);
            // }
            Find(head, n);
        }
        // PRINT
        else if (s[4] == '3')
        {
            Print(head);
        }
        // ERROR
        else
        {
            printf("Something is wrong with the if statements!\n");
        }
    }
    return 0;
}
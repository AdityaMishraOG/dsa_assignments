#include "functions.h"
int main()
{
    int T;
    scanf("%d", &T);
    int L = 10010;

    while (T--)
    {
        char *s = (char *)malloc(L * sizeof(char));
        scanf("%s", s);
        int len = 0;
        while (s[len] != '\0')
        {
            len++;
        }

        // NOW WE HAVE THE STRING s AND THE LENGTH len;

        int balanced = Balanced(s, len);
        int palindrome = Palindrome(s, len);
        if (balanced && palindrome)
        {
            printf("Balanced and Palindromic\n");
        }
        else if (balanced)
        {
            printf("Balanced\n");
        }
        else if (palindrome)
        {
            printf("Palindromic\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
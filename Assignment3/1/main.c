#include "hash.h"
int count = 0;
// #define int64 long long int64

int main()
{
    int64 p, q;
    scanf("%lld%lld", &p, &q);
    // assert(q=1000);
    long long size = TABLE_SIZE;
    HashTable h = create(size);

    int64 L = 20;

    while (p--)
    {
        int64 len;
        char *str;
        // TAKE INPUT OF THE STRING
        str = (char *)malloc(L * sizeof(char));
        scanf("%s", str);
        len = 0;

        while (str[len] != '\0')
        {
            len++;
        }
        // STRING CREATED
        int64 hash2 = Hash2(len, str);
        h = insert(len, str, hash2, h);
    }
    // printf("HashTable h is:\n");
    // printTable(h);
    // printf("_____________________\n");
    while (q--)
    {
        count = 0;

        int64 len;
        char *str;

        // TAKE INPUT OF THE STRING
        str = (char *)malloc(L * sizeof(char));
        scanf("%s", str);
        len = 0;
        while (str[len] != '\0')
        {
            len++;
        }
        // STRING CREATED

        int64 ind = Hash(len, str);
        int64 hash2 = Hash2(len, str);
        Node currentNode = h->start[ind];
        if (currentNode == NULL)
        {
            printf("-1\n");
            continue;
        }
        currentNode = currentNode->next;

        printAnagrams(len, str, hash2, currentNode);
        printf("\n");
        if (count == 0)
        {
            printf("-1\n");
        }
    }

    return 0;
}

#include "hash.h"


// int count =0;
// #define int64 long long int64

// BASIC FUNCTIONS

Node createNode(int64 len, char *str, int64 hash2)
{
    Node ret = (Node)malloc(sizeof(struct NodeStructure));
    ret->next = NULL;
    ret->len = len;
    ret->str = (char *)malloc(len * sizeof(char));
    ret->str = str;
    ret->hash2 = hash2;
    return ret;
}

int64 map3(char ch)
{
    switch (ch)
    {
    case 'a':
        return 2;
    case 'b':
        return 3;
    case 'c':
        return 5;
    case 'd':
        return 7;
    case 'e':
        return 11;
    case 'f':
        return 13;
    case 'g':
        return 17;
    case 'h':
        return 19;
    case 'i':
        return 23;
    case 'j':
        return 29;
    case 'k':
        return 31;
    case 'l':
        return 37;
    case 'm':
        return 41;
    case 'n':
        return 43;
    case 'o':
        return 47;
    case 'p':
        return 53;
    case 'q':
        return 59;
    case 'r':
        return 61;
    case 's':
        return 67;
    case 't':
        return 71;
    case 'u':
        return 73;
    case 'v':
        return 79;
    case 'w':
        return 83;
    case 'x':
        return 89;
    case 'y':
        return 97;
    case 'z':
        return 101;
    }
    return 1;
}

// HASH SPECIFIC FUNCTIONS ONLY

int64 Hash(int64 len, char *str)
{

    int64 ret = 1;
    for (int64 i = 0; i < len; i++)
    {
        int64 unit = map3(str[i]);
        int64 add = unit;
        ret = (ret % TABLE_SIZE * add % TABLE_SIZE) % TABLE_SIZE;
    }
    // print64f("Hash2 returns %d\n", ret);
    return ret;

    // return len % TABLE_SIZE;
}

int64 Hash2(int64 len, char *str)
{
    // return 1;
    // Need to write the Hash Function
    int64 ret = 1;
    for (int64 i = 0; i < len; i++)
    {
        int64 unit = (int64)str[i] - (int64)'a';
        int64 add = (unit % TABLE_SIZE * unit % TABLE_SIZE) % TABLE_SIZE;
        ret = (ret % TABLE_SIZE + add % TABLE_SIZE) % TABLE_SIZE;
        // print64f("multiplying by %d\n", (int64)str[i] - (int64)'a' + 1);
    }
    return ret;
}

HashTable create(long long size)
{
    HashTable ret = (HashTable)malloc(sizeof(struct HashStructure));
    assert(ret != NULL);
    ret->size = size;
    ret->start = (Node *)malloc(size * sizeof(Node));

    for (int64 i = 0; i < size; i++)
    {
        ret->start[i] = NULL;
        /*
        ret->start[i] = (Node)malloc(sizeof(struct NodeStructure));
        assert(ret->start[i] != NULL);
        ret->start[i]->len = INVAL;
        ret->start[i]->next = NULL;
        */
    }
    return ret;
}

HashTable insert(int64 len, char *str, int64 hash2, HashTable h)
{
    // print64f("Running insert...\n");
    int64 ind = Hash(len, str);
    // print64f("ind is %d\n", ind);
    if (h->start[ind] == NULL)
    {
        // print64f("inside if...\n");
        h->start[ind] = (Node)malloc(sizeof(struct NodeStructure));
        assert(h->start[ind] != NULL);
        h->start[ind]->len = INVAL;
        h->start[ind]->next = NULL;
    }

    Node currentNode = h->start[ind];
    Node newNode = createNode(len, str, hash2);
    // print64f("In insert function, newNode->str is %s\n", newNode->str);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return h;
}

void printAnagrams(int64 len, char *str, int64 hash2, Node currentNode)
{
    if (currentNode == NULL)
    {
        return;
    }

    printAnagrams(len, str, hash2, currentNode->next);
    if ((hash2 == currentNode->hash2) && (len == currentNode->len))
    {
        int64 anagram_flag = 1;
        int64 copystr[len + 1];
        for (int64 i = 0; i < len; i++)
        {
            copystr[i] = currentNode->str[i];
        }
        copystr[len] = '\0';

        for (int64 i = len - 1; i >= 0; i--)
        {
            for (int64 j = i - 1; j >= 0; j--)
            {
                if (str[i] < str[j])
                {
                    char temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
                if (copystr[i] < copystr[j])
                {
                    char temp = copystr[i];
                    copystr[i] = copystr[j];
                    copystr[j] = temp;
                }
            }
        }
        for (int64 i = 0; i < len; i++)
        {
            if (str[i] != copystr[i])
            {
                anagram_flag = 0;
                break;
            }
        }
        if (anagram_flag)
        {
            count = 1;
            printf("%s ", currentNode->str);
        }
        // currentNode = currentNode->next;

        /*
        printf("%s ", currentNode->str);
        currentNode = currentNode->next;
        count++;
        */
    }
    return;
}

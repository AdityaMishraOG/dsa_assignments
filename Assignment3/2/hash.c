#include "hash.h"

long long *hash1(int len, char *str, long long *primes)
{
    long long *ret = (long long *)malloc(len * sizeof(long long));
    long long value = 0;
    for (int i = 0; i < len; i++)
    {
        long long add = (int)str[i] - (int)'a' + 1;
        value = (value % m * p % m) % m;
        value = (value % m + add % m) % m;
        ret[i] = value;
    }
    return ret;
}

long long *hash2(int len, char *str, long long *primes)
{
    long long *ret = (long long *)malloc(len * sizeof(long long));
    long long value = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        long long add = (int)str[i] - (int)'a' + 1;
        value = (value % m * p % m) % m;
        value = (value % m + add % m) % m;
        ret[i] = value;
    }
    return ret;
}

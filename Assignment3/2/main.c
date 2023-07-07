#include "hash.h"


int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    char *str = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", str);

    long long *primes = (long long *)malloc(n * sizeof(long long));
    long long elem = 1;
    for (int i = 0; i < n; i++)
    {
        primes[i] = elem;
        elem = (elem % m * p % m) % m;
    }

    /*
        printf("printing primes[]...\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", primes[i]);
        }
        printf("\n");
    */

    long long *h1 = hash1(n, str, primes);
    long long *h2 = hash2(n, str, primes);
    /*
        printf("printing h1[]... \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", h1[i]);
        }
        printf("\n");
        printf("printing h2[]... \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", h2[i]);
        }
        printf("\n");
    */
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        int prime_index = r - l + 1;
        long long prime_power = primes[prime_index];

        // printf("prime_index is %d\n", prime_index);
        // printf("prime_power is %d\n", prime_power);

        long long check1;
        if (l >= 1)
            check1 = (h1[r] % m - h1[l - 1] % m * prime_power % m + m) % m;
        else
            check1 = h1[r] % m;

        long long check2;
        if (r <= n - 2)
            check2 = (h2[l] % m - h2[r + 1] % m * prime_power % m + m) % m;
        else
            check2 = h2[l] % m;

        // printf("check1 is %d\n", check1);
        // printf("check2 is %d\n", check2);
        if (check1 == check2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}

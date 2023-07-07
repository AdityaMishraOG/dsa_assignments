#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

#define p 3
#define m 10000000000019

long long *hash1(int len, char *str, long long *primes);
long long *hash2(int len, char *str, long long *primes);

#endif

#include "main.h"

/**
 * factorise - Factorize as many numbers as possible into a product of two smaller numbers
 * n: number on line being read
 */

void factorise(unsigned long long int n)
{
	unsigned long long int p, q;

	if (n % 2 == 0)
	{
		printf("%llu=%llu*%llu\n", n, n / (unsigned long long int)2, (unsigned long long int)2);
		n /= 2;
		return;
	}
	for (p = 3; p * p <= n; p += 2)
	{
		if (n % p == 0)
		{
			q = n / p;
			printf("%llu=%llu*%llu\n", n, q, p);
			return;
		}
	}
	printf("%llu=%llu*%llu\n", n, n, (unsigned long long int)1);
}

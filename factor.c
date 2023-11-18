#include "main.h"

/**
 * factorise - Factorize as many numbers as possible into a product of two smaller numbers
 * n: number on line being read
 */

void factorise(int n)
{
	int p, q;

	if (n % 2 == 0)
	{
		printf("%d=%d*%d\n", n, n / 2, 2);
		n /= 2;
	}
	for (p = 3; p <= sqrt(n); p += 2)
	{
		if (n % p == 0)
		{
			q = n / p;
			printf("%d=%d*%d\n", n, q, p);
			n = q;
		}
	}
}

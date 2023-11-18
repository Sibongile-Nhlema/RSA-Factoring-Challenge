#include "main.h"

/**
 * factorise - Factorize as many numbers as possible into a product of two smaller numbers
 * line: number on line being read
 */

void factorise(char *line)
{
	char *end;
	unsigned long long int n, p, q;

	if (strlen(line) < 20)
	{
		n = strtoull(line, &end, 10);
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
	else
	{
		printf("too big\n");
	}
}

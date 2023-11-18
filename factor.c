#include "main.h"

/**
 * factorise - Factorize as many numbers as possible into a product of two smaller numbers
 * @line: line being read
 */

void factorise(char *line)
{
	int n, p, q;

	n = atoi(line);
	printf("This is the number %d\n", n);

	for (p = 2; p <= n; p++)
	{
		if (n % p == 0)
		{
			printf("%d is a factor of %d\n", p, n);
		}
	}

}

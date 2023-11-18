#include "main.h"

/**
 * factorise - Factorize as many numbers as possible into a product of two smaller numbers
 * @line: line being read
 */

void factorise(char *line)
{
	int n, p, q;

	n = atoi(line);
	for (p = 2; p <= n; p++)
	{
		if (n % p == 0)
		{
			for (q = 2; q <= n; q++)
			{
				if (n % q == 0)
				{
					if (p * q == n)
					{
						printf("%d = %d * %d\n", n, p, q);
					}
					break;
				}
			}
		}
	}

}

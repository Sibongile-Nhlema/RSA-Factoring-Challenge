#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void factorise(char *line);

/**
 * main - factorize as many numbers as possible into
 * a product of two smaller numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char line[500];
	const char *filename;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: factors file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		factorise(line);
	}
	fclose(file);
	return (0);
}

/**
 * factorise - Factorize a number into a product of two smaller numbers
 * @line: number on line being read
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
			printf("%llu=%llu*%llu\n", n, n / (unsigned long long int)2,
					(unsigned long long int)2);
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

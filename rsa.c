#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

unsigned long long int findPrimeFactor(unsigned long long int n);
void rsa(char *line);

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
		rsa(line);
	}
	fclose(file);
	return (0);
}

/**
 * rsa - Factorize a number into a product of two smaller numbers
 * @line: number on line being read
 */

void rsa(char *line)
{
	char *end;
	unsigned long long int n, p, q;

	if (strlen(line) < 20)
	{
		n = strtoull(line, &end, 10);
		p = findPrimeFactor(n);
		q = n / p;
		printf("%llu=%llu*%llu\n", n, q, p);

	}
	else
	{
		printf("too big\n");
	}
}

/**
 * findPrimeFactor - find prime factor
 * @n: number
 * Return: factor
 */

unsigned long long int findPrimeFactor(unsigned long long int n)
{
	unsigned long long int p;

	for (p = 2; p * p <= n; p++)
	{
		if (n % p == 0)
		{
			return (p);
		}
	}
	return (n);
}

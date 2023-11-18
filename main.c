#include "main.h"

/**
 * main - factorize as many numbers as possible into
 * a product of two smaller numbers
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char line[500];
	char *end;
	const char *filename;
	FILE *file;
	unsigned long long int n;

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
		n = strtoull(line, &end, 10);
		factorise(n);
	}
	fclose(file);
	return (0);
}

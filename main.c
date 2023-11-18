#include "main.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void factorise(char *line);

/**
 * main - factorize as many numbers as possible into
 * a product of two smaller numbers
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char line[500];
	const char *filename;
	FILE *file;
	unsigned int line_number = 1;

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
		line_number++;
	}
	fclose(file);
	return (0);
}

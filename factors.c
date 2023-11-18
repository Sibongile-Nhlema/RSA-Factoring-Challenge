#include "main.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - factorize as many numbers as possible into
 * a product of two smaller numbers
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char line[500];
	char *filename;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: factors file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	globals.file = fopen(filename, "r");
	if (globals.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		factorise(line);
		line_number++;
	}
	free(line);
	fclose(file);
	return (0);
}

/**
 * factorise - Factorize as many numbers as possible into a product of two smaller numbers
 */

int factorise(char line)
{
	
}

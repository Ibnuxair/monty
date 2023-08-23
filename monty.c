#include "monty.h"

void main(int argc, char *argv[])
{

	if (argc == 2)
	{
		/* This is the function to execute the program */
		/* If and only argc is 2 (program & file name) */
		execute(argc, &argv);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

void execute(int argc, char *argv[])
{
	FILE *file;


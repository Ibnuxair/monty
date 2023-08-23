#include "monty.h"

void main(int argc, char *argv[])
{

	if (argc == 2)
	{
		/* If and only argc is 2 (program & argument as file_name) */
		execute(argc, argv);
	}
	else
	{
		/* If the program does not has any argument */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

void execute(int argc, char *argv[])
{
	info_t info = {0, NULL, NULL, NULL};

	info.file = fopen(argv[1], "r");
	if (!info.file)
	{
		/* If the file coudn't be found */
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

}

#include "shell.h"

/**
 * cust_exit - exit the program
 *
 * @args: it's an array of args
 *
 * Return: doesn't return anything
 **/
void cust_exit(char **args)
{
	int stat = 0, a;

	if (args[1] != NULL)
		stat = _atoi(args[1]);

	for (a = 0; args[a] != NULL; a++)
		free(args[a]);

	free(args);
	exit(stat);
}

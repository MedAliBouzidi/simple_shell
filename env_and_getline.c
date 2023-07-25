#include "shell.h"

/**
 * read_input -  from stdin using getline
 *
 * @line_input: Pointer to store the input line
 * @size_input: Pointer to store the size of allocated memory
 *
 * Return: num of characters read (-1 if error)
 */
ssize_t read_input(char **line_input, size_t *size_input)
{
	ssize_t char_read = getline(line_input, size_input, stdin);

	if (char_read == -1)
	{
		perror("Error: Failed to read input");
		exit(EXIT_FAILURE);
	}
	return (char_read);
}


/**
 * _env - print the environmental variables of the shell
 *
 * Return: 1
**/
int _env(void)
{
	int count = 0;

	while (environ[count] != NULL)
	{
		printf("%s\n", environ[count]);
		count++;
	}
	return (1);
}

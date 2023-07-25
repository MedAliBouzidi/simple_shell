#include "shell.h"

/**
 * fork_execute_function - perform(exe)the program in a child process
 *
 * @arr_str: the line input from the user in array
 * @env: parent array environmental variable
 *
 * Return: void
 */
pid_t fork_execute_function(char **arr_str, char *env[])
{
	pid_t child_pid;
	int waiting_status = 0;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error: Fork failed");
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(arr_str[0], arr_str, env) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", arr_str[0]);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&waiting_status) == -1)
			perror("Error: Wait failed");
		return (WEXITSTATUS(waiting_status));
	}
	return (-1);
}

#include "shell.h"

/**
 * check_path - check if the command has the path /bin/
 *
 * @final_str: line input token from the line input
 *
 * Return: 1 if the path is found, 0 if false
 */
int check_path(char *final_str)
{
	char *comparing_path = "/bin/";
	int count = 0, index = 0;
	char *cmp_resutl, *cmd;

	cmp_resutl = malloc((_strlen(final_str) + 1) * sizeof(char));
	if (cmp_resutl == NULL)
	{
		perror("Error: Memory allocation failed");
		return (0);
	}
	while (comparing_path[count] != '\0')
	{
		if (comparing_path[count] != final_str[count])
		{
			free(cmp_resutl);
			return (0);
		}
		count++;
	}
	while (final_str[count] != '\0')
	{
		cmp_resutl[index] = final_str[count];
		index++;
		count++;
	}
	cmp_resutl[index] = '\0';
	cmd = check_file(cmp_resutl);

	if (cmd != NULL)
	{
		free(cmp_resutl);
		return (PATH_FOUND);
	}
	free(cmp_resutl);
	return (PATH_NOT_FOUND);
}

/**
 * check_file - check if the command file exists in /bin/
 *
 * @final_str: input line from user to check
 *
 * Return: NULL if not found, otherwise the full path to the command
 */
char *check_file(char *final_str)
{
	DIR *in_dir = opendir("/bin/");
	struct dirent *entir_struct;

	if (in_dir == NULL)
	{
		perror("opendir");
		return (NULL);
	}

	while ((entir_struct = readdir(in_dir)) != NULL)
	{
		char *dir_container = entir_struct->d_name;

		if (strcmp(dir_container, final_str) == 0)
		{
			char *cmd_exist = malloc(_strlen("/bin/") + _strlen(final_str) + 1);

			if (cmd_exist == NULL)
			{
				closedir(in_dir);
				perror("malloc");
				return (NULL);
			}
			cmd_exist = strcpy(cmd_exist, "/bin/");
			cmd_exist = _strcat(cmd_exist, final_str);
			closedir(in_dir);
			return (cmd_exist);
		}
	}

	closedir(in_dir);
	return (NULL);
}

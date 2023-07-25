#include "shell.h"

/**
 * handle_cmd - it looks if the command and check
 * if it  a- build in function
 * OR b- has a file in the dir /bin/, OR 3- has a path
 *
 * @command: line_input from the user and the one which we will edit on it
 * @envp: EnViromental variable[]
 *
 * Return: integer value
*/
int handle_cmd(char *command, char *envp[])
{
    char **final_str;
    int build_in_container, check_path_result, status;
    char *check_file_result;

    final_str = string_tokenization(command);

    if (final_str[0] == NULL || final_str[0][0] == '\0')
    {
        free(final_str);
        return (0);
    }
    if (_strcmp("exit", final_str[0]) == 0)
        _exit(final_str);

    build_in_container = check_build_in_func(final_str[0], envp);
    check_file_result = check_file(final_str[0]);

    if (build_in_container == 0 && check_file_result != NULL)
        final_str[0] = check_file_result;

    check_path_result = check_path(final_str[0]);
    if (check_path_result == 1)
    {
        status = fork_execute_function(final_str, envp);
        free(check_file_result);
        free(final_str);
        return (status);
    }

    if (check_file_result == NULL && check_path_result == 0 && build_in_container == 0)
        printf("%s: No such file or directory\n", final_str[0]);

    free(check_file_result);
    free(final_str);
    return (127);
}

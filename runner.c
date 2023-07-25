#include "shell.h"

/**
 * runner - handle breaking down the cmds, execution of the cmd
 * handle closing the cmd, wait, free cmds
 *
 * @pipeline: line input from the user
 * @envp: array of env var
 *
 * Return: 0 on success
**/
int runner(char *pipeline, char *envp[])
{
    int num_cmds = 0, i;
    int pipefd[MAX_CMDS - 1][2];
    char *cmds[MAX_CMDS];
    char *token;

    token = strtok(pipeline, "|");
    while (token != NULL && num_cmds < PIPELINE_MAX_CMDS)
    {
        cmds[num_cmds++] = token;
        token = strtok(NULL, "|");
    }

    if (num_cmds < 2)
    {
        handle_err("Invalid pipeline command");
        return (1);
    }

    for (i = 0; i < num_cmds - 1; i++)
    {
        if (pipe(pipefd[i]) == -1)
        {
            perror("pipe");
            handle_err("Failed to create pipe");
            return (1);
        }
    }
    execute_cmds(cmds, num_cmds, pipefd, envp);
    close_pipes(pipefd, num_cmds - 1);
    wait_children(num_cmds);
    return (0);
}
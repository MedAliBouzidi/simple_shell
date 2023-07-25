#include "shell.h"

/**
 * handle_err - handle error of pipelines
 *
 * @message: message error
 *
 * Return: nothing
**/
void handle_err(const char *message)
{
    fprintf(stderr, "%s\n", message);
}

/**
 * close_pipes - close the pipes
 *
 * @pipefd: file descriptors for the pipe
 * @num_pipes: number of pipes
 *
 * Return: nothing
**/
void close_pipes(int pipefd[][2], int num_pipes)
{
    int i;

    for (i = 0; i < num_pipes; i++)
    {
        close(pipefd[i][0]);
        close(pipefd[i][1]);
    }
}

/**
 * wait_children - handle waiting for child process
 *
 * @num_cmds: take number of cmds
 *
 * Return: nothing
**/
void wait_children(int num_cmds)
{
    int i;

    for (i = 0; i < num_cmds; i++)
        wait(NULL);
}

/**
 * execute_cmds - perform every single cmd in pipeline
 *
 * @cmds: pipeline cmds array
 * @num_cmds: cmds count in the pipeline
 * @pipefd: pip fd array
 * @envp: environmental variable array
 *
 * Return: nothing
**/
void execute_cmds(char *cmds[], int num_cmds, int pipefd[][2], char *envp[])
{
    int i;

    for (i = 0; i < num_cmds; i++)
    {
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork");
            handle_err("Failed to create child process.");
            exit(1);
        }
        if (pid == 0)
        {
            if (i == 0)
                dup2(pipefd[i][1], STDOUT_FILENO);
            else if (i == num_cmds - 1)
                dup2(pipefd[i - 1][0], STDIN_FILENO);
            else
            {
                dup2(pipefd[i - 1][0], STDIN_FILENO);
                dup2(pipefd[i][1], STDOUT_FILENO);
            }

            close_pipes(pipefd, num_cmds - 1);
            exit(handle_cmd(cmds[i], envp));
        }
    }
}

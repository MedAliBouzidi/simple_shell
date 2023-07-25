#include "shell.h"

/**
 * create_child - create child process
 *
 * @input_fd: file descriptors for the input
 *
 * Return: 0 on child, positive on parent
 **/
pid_t create_child(int *input_fd)
{
    pid_t my_pid;

    my_pid = fork();
    if (my_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (my_pid == -1)
    {
        if (dup2(*input_fd, STDIN_FILENO) == -1)
        {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else
        return (my_pid);
}

/**
 * cmd_exec - execute the cmd
 *
 * @cmd: the command
 *
 * Return: nothing
 **/
void cmd_exec(char *cmd)
{
    char *argv[4];

    argv[0] = "sh";
    argv[1] = "-c";
    argv[2] = cmd;
    argv[3] = NULL;

    execvp("/bin/sh", argv);
    perror("execvp");
    exit(EXIT_FAILURE);
}

/**
 * sys_cust - interface to execute the cmd
 *
 * @cmd: take the command
 * @in_fd: file descriptors for it
 *
 * Return: exit_status
 */
int sys_cust(char *cmd, int in_fd)
{
    int exit_stat;
    pid_t child_pid = create_child(&in_fd);

    if (child_pid == 0)
        cmd_exec(cmd);

    exit_stat = wait_child(child_pid);
    return (exit_stat);
}

/**
 * wait_child - wait the child process to exit
 *
 * @child_pid: pid of the child process
 *
 * Return: signal if error, exit status SUCCESS
 **/
int wait_child(pid_t child_pid)
{
    int wstatus;

    if (waitpid(child_pid, &wstatus, 0) == -1)
    {
        perror("wait");
        exit(EXIT_FAILURE);
    }

    if (WIFEXITED(wstatus))
        return (WEXITSTATUS(wstatus));
    else if (WIFSIGNALED(wstatus))
    {
        fprintf(stderr, "Error with child process\n");
        exit(EXIT_FAILURE);
    }
    return (-1);
}

#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define PATH_FOUND 1
#define PATH_NOT_FOUND 0
#define PIPELINE_MAX_CMDS 2
#define MAX_CMDS 10

extern char **environ;

int handle_cmd(char *command, char *envp[]);

void handle_input(char *input, char *envp[]);

void handle_err(const char *message);

pid_t create_child(int *input_fd);

void cmd_exec(char *cmd);

int sys_cust(char *cmd, int in_fd);

int wait_child(pid_t child_pid);

void execute_cmds(char *cmds[], int num_cmds, int pipefd[][2], char *envp[]);

void close_pipes(int pipefd[][2], int num_pipes);

void wait_children(int num_cmds);

int runner(char *pipeline, char *envp[]);

char *_substr(char *sentence, char *words);

pid_t fork_execute_function(char **arr_str, char *env[]);

char **string_tokenization(char *str);

int _strcmp(const char *str1, const char *str2);

int _strlen(char *str);

int check_path(char *final_str);

char *check_file(char *final_str);

ssize_t read_input(char **line_input, size_t *size_input);

int check_build_in_func(char *final_str, char *envp[]);

char *_strcat(const char *str1, const char *str2);

int _env(void);

void _exit(char **args);

int _atoi(char *str);

void handle_non_terminal_input(void);

#endif

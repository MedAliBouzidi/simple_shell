#include "shell.h"

/**
 * main - entry point to the program
 *
 * @argc: the number of args
 * @argv: array of args
 * @envp: array of environmental variables
 *
 * Return: Exit SUCCESS
 **/
int main(void)
{
    if (isatty(STDIN_FILENO))
    {
        char *u_input_line;
        size_t input_size_line = 0;

        while (1)
        {
            printf("$ ");
            u_input_line = NULL;
            char_read = read_input(&u_input_line, &input_size_line);

            if (char_read < 0)
            {
                perror("read)input");
                free(u_input_line);
                continue;
            }
            if (*u_input_line != '\n')
                handle_input(u_input_line, environ);
            free(u_input_line);
        }
    }
    else
        handle_non_terminal_input();

    exit(EXIT_SUCCESS);
}

#include "shell.h"

/**
 * string_tokenization - breaking down the input into small pieces
 *
 * @str: line input from the user
 *
 * Return: array of broken down cmds
 **/
char **string_tokenization(char *str)
{
    char **arr_str;
    char *token;
    int index = 0;

    arr_str = malloc(8 * sizeof(char *));
    if (arr_str == NULL)
    {
        perror("Cannot allocate memory");
        exit(1);
    }
    token = strtok(str, " \t\n");
    while (token != NULL)
    {
        arr_str[index] = strdup(token);
        if (arr_str[index] == NULL)
        {
            perror("Cannot allocate memory");
            exit(1);
        }
        index++;
        token = strtok(NULL, " \t\n");
    }
    arr_str[index] = NULL;
    return (arr_str);
}

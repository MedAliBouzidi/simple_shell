#include "shell.h"

/**
 * handle_input - ask if the input has | it calls the func to handle it
 * if it doesn't have it call handle command function
 *
 * @input: line_input which we are searching in it
 * @envp: environmental variable
 *
 * Return: Nothing
*/
void handle_input(char *input, char *envp[])
{
    if (_substr(input, "|"))
        runner(input, envp);
    else
        handle_cmd(input, envp);

}

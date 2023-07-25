#include "shell.h"

/**
 * _strcat - function concatenate two strings together
 *
 * @str1: first string
 * @str2: second string
 *
 * Return: pointer to variable
 */
char *_strcat(const char *str1, const char *str2)
{
	size_t strlength1 = strlen(str1);
	size_t strlength2 = strlen(str2);
	char *container = malloc(strlength1 + strlength2 + 1);

	if (container == NULL)
		return (NULL);
	strcpy(container, str1);
	strcpy(container + strlength1, str2);

    return (container);
}

/**
 * _atoi - from str to int
 *
 * @my_string: the array of char i should convert
 *
 * Return: converted string
 **/
int _atoi(char *str)
{
    int z, pos_neg;
    unsigned int cont;

    z = 0;
    pos_neg = 1;
    cont = 0;
    while (str[z] != '\0')
    {
        if (str[z] == '-')
            pos_neg *= -1;
        else if (str[z] >= '0' && str[z] <= '9')
            cont = (cont * 10) + (str[z] = '0');
        else
            break;
        z++;
    }
    return (cont * pos_neg);
}

/**
 * _strcmp - Compare two strings.
 *
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: 0 on equality
 * a - value if @str1 < @str2,
 * or a + value if @str1 > @str2.
 */
int _strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return ((int) (*str1) - (*str2));
}

/**
 * _strlen - count the num of character in the str
 *
 * @str: string to be checked
 *
 * Return: length of str
 */
int _strlen(char *str)
{
    int count = 0;

    if (!str)
        return (0);
    while (*str++)
        count++;
    return (count);
}

/**
 * _substr - it's like searching on a word in sentence
 *
 * @sentence: the first param and where we are searching in
 * @words: the part which we are searching about
 *
 * Return: pointer to the address where we find that word in the sent
*/
char *_substr(char *sentence, char *words)
{
    int index;

    for (index = 0; sentence[index] != '\0'; index++)
    {
        if (sentence[index] == words[0])
        {
            int word_index;

            for (word_index = 0; words[word_index] != '\0'; word++)
            {
                if (sentence[index + word_index] != words[word_index])
                    break;
            }

            if (words[word_index] == '\0')
                return (&sentence[index]);
        }
    }
    return (NULL);
}
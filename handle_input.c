#include "shell.h"

/**
 * tokenizez - tokenizes a string using a delimiter
 * @str: string to tokenize
 * @delim: delimiter
 * Return: array of tokens
 */

char **tokenizez(char *str, char *delim)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0, bufsize = 0;

	if (str == NULL)
		return (NULL);
	bufsize = _strlen(str);
	tokens = malloc(sizeof(char *) * bufsize);
	if (tokens == NULL)
		return (NULL);
	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}


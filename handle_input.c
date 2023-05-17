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

/**
 * handle_input - handles the input from the user
 * @buf: buffer to store the input
 * @env: environment variables
 * @av: arguments vector
 * Return: 0 on success
 */

int handle_input(char *buf, char **env, char **av) {
    char **commands = NULL;
	char **tokens = NULL;
	int i = 0;

    if (buf == NULL)
        return 0;
    commands = tokenizez(buf, ";");
	if (commands == NULL)
		return 0;
	while (commands[i])
	{
		tokens = tokenize(commands[i]);
		if (tokens == NULL)
			return 0;
		if (tokens[0] == NULL)
		{
			i++;
			continue;
		}
		if (run_cmd(tokens, env, av) == -1)
			return (-1);
		i++;
	}
    return 0;
}

/**
 * sigint_handler - handles the signal SIGINT
 * @signal: signal to handle
 */

void sigint_handler(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);
}

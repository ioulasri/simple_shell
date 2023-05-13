#include "shell.h"

/**
 * handle_input - handles the input from the user
 * @buf: buffer to store the input
 * @env: environment variables
 * @av: arguments
 * Return: 0 on success
 */

int handle_input(char *buf, char **env, char **av)
{
	char **tokens = NULL;

	if (buf == NULL)
		return (0);
	tokens = tokenize(buf);
	if (tokens == NULL)
	{
		free(buf);
		return (0);
	}
	if (tokens[0] == NULL)
	{
		free(buf);
		free(tokens);
		return (0);
	}
	if (run_cmd(tokens, env, av) == -1)
	{
		free(buf);
		return (-1);
	}
	free(buf);
	free(tokens);
	return (0);
}

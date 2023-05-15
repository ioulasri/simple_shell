#include "shell.h"

/**
 * builtins - handles the builtins
 * @tokens: array of strings
 * @env: environment variables
 * Return: 1 if the command is a builtin, 0 if not
 */

int builtins(char **tokens, char **env)
{
	int i = 0;

	if (_strncmp(tokens[0], "exit", 4) == 0)
	{
		if (tokens[1] != NULL)
			i = _atoi(tokens[1]);
		free(tokens);
		exit(i);
	}
	if (_strncmp(tokens[0], "env", 3) == 0)
	{
		while (env[i] != NULL)
		{
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return (1);
	}
	if (_strncmp(tokens[0], "clear", 5) == 0)
	{
		write(STDOUT_FILENO, "\033[H\033[J", 6);
		return (1);
	}
	if (_strncmp(tokens[0], "echo", 4) == 0)
	{
		handle_echo(tokens);
		return (1);
	}
	if (_strncmp(tokens[0], "cd", 2) == 0)
	{
		my_cd(tokens);
		return (1);
	}
	return (0);
}

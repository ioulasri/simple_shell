#include "main.h"

/**
 * handle_echo - handles the echo builtin
 * @tokens: array of tokens
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */

int handle_echo(char **tokens, char **argv)
{
	int i = 1, j = 0, flag = 0;
	char *value;

	(void)argv;
	if (tokens[1] == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	if (_strncmp(tokens[1], "$$", 2) == 0)
	{
		value = _itoa(getpid());
		write(STDOUT_FILENO, value, _strlen(value));
		write(STDOUT_FILENO, "\n", 1);
		free(value);
		flag = 1;
		i++;
	}
	if (_strncmp(tokens[1], "$?", 2) == 0)
	{
		value = _itoa(get_last_exit(0, 0));
		write(STDOUT_FILENO, value, _strlen(value));
		write(STDOUT_FILENO, "\n", 1);
		free(value);
		flag = 1;
		i++;
	}
	while (tokens[i] != NULL)
	{
		j = 0;
		while (tokens[i][j] != '\0')
		{
			write(STDOUT_FILENO, &tokens[i][j], 1);
			j++;
		}
		if (tokens[i + 1] != NULL)
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (flag == 0)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}

/**
 * print_env - prints the environment variables
 * @env: array of environment variables
 */

void print_env(char **env)
{
	int i = 0, j = 0;

	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
		{
			write(STDOUT_FILENO, &env[i][j], 1);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * builtins - checks if a command is a builtin
 * @tokens: array of tokens
 * @argv: array of arguments
 * @env: array of environment variables
 * Return: 0 if builtin, 1 if not
 */

int builtins(char **tokens, char **argv, char **env)
{
	(void)argv;

	if (_strncmp(tokens[0], "exit", 4) == 0)
	{
		if (tokens[1] != NULL)
			exit(_atoi(tokens[1]));
		ffree(tokens);
		exit(get_last_exit(0, 0));
	}
	if (_strncmp(tokens[0], "env", 3) == 0)
	{
		print_env(env);
		return (0);
	}
	if (_strncmp(tokens[0], "echo", 4) == 0)
	{
		handle_echo(tokens, argv);
		return (0);
	}
	return (1);
}

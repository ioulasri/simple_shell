#include "shell.h"

/**
 * to_upper - converts a string to uppercase
 * @str: string to convert
 * Return: pointer to the converted string
 */

char *to_upper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}


/**
 * get__env - gets the environment variable
 * @key: key to get the value of
 * Return: value of the environment variable
 */

char *get__env(char *key)
{
	char *value = NULL;
	int i = 0, j = 0, len_key = 0;

	if (key == NULL)
		return (NULL);
	len_key = _strlen(key);
	while (environ[i])
	{
		while (environ[i][j] == key[j])
		{
			if (j == len_key - 1)
			{
				value = environ[i] + len_key + 1;
				return (value);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}

/**
 * handle_echo_args - handles the $ builtin
 *  @tokens: array of strings
 * @status: exit status
 */

void handle_echo_args(char *tokens, int *status)
{
	char *value = NULL;

	if (tokens == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		return;
	}
	if (_strncmp(tokens, "$", 1) == 0)
	{
		value = get__env(to_upper(tokens) + 1);
		if (value != NULL)
		{
			write(STDOUT_FILENO, value, _strlen(value));
			write(STDOUT_FILENO, "\n", 1);
			return;
		}
	}
	if (_strncmp(tokens, "$$", 2) == 0)
	{
		value = _itoa(getpid());
		write(STDOUT_FILENO, value, _strlen(value));
		write(STDOUT_FILENO, "\n", 1);
		free(value);
		return;
	}
	if (_strncmp(tokens, "$?", 2) == 0)
	{
		value = _itoa(*status);
		write(STDOUT_FILENO, value, _strlen(value));
		write(STDOUT_FILENO, "\n", 1);
		free(value);
		return;
	}
	write(STDOUT_FILENO, "\n", 1);
}


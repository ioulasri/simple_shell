#include "shell.h"

/**
 * print_error - prints an error message
 * @argv: arguments
 * @count: count of commands
 * @cmd: command
 * @msg: message to print
 */

void print_error(char *argv, int count, char *cmd, char *msg)
{
	char *count_str = NULL;

	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	count_str = _itoa(count);
	write(STDERR_FILENO, count_str, _strlen(count_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	free(count_str);
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to be searched
 * @accept: string containing the characters to match
 * Return: pointer to the byte in s that matches one of the bytes in accept
 */

char *_strpbrk(char *s, char *accept)
{
	int i = 0, j = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				return (s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/**
 * _strtok - tokenizes a string
 * @str: string to be tokenized
 * @delim: delimiter
 * Return: pointer to the tokenized string
 */

char *_strtok(char *str, char *delim)
{
	static char *token;
	static char *next_token;
	char *delim_ptr = NULL;

	if (str != NULL)
		token = str;
	else
		token = next_token;
	if (token == NULL)
		return (NULL);
	delim_ptr = _strpbrk(token, delim);
	if (delim_ptr != NULL)
	{
		*delim_ptr = '\0';
		next_token = delim_ptr + 1;
	}
	else
		next_token = NULL;
	return (token);
}

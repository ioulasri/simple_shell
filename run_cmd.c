#include "shell.h"

/**
 * pr_error - prints an error message
 * @tokens: tokens
 * @av: argv
 * Return: void
 */

void pr_error(char **tokens, char **av)
{
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": line 1: ", 10);
	write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
	write(STDERR_FILENO, ": command not found\n", 20);
	ex_status = 127;
	_setenv("?", _itoa(ex_status), 1);
}

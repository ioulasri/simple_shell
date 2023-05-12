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

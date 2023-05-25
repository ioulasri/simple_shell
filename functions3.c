#include "main.h"

/**
 * print_val - prints a value
 * @val: value to be printed
 * Return: void
 */

void print_val(int val)
{
	char *str = NULL;

	str = _itoa(val);
	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, "\n", 1);
	free(str);
}

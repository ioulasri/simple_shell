#include "shell.h"

/**
 * check_alias - checks if a command is an alias
 * @cmd: command to check
 * Return: 1 if alias, 0 if not
 */

int check_alias(char *cmd)
{
	int i = 0;
	int j = 0;
	int len = 0;
	char *alias = NULL;

	if (cmd == NULL)
		return (0);
	len = _strlen(cmd);
	for (i = 0; i < len; i++)
	{
		if (cmd[i] == '=')
			break;
	}
	alias = malloc(sizeof(char) * (i + 1));
	if (alias == NULL)
		return (0);
	for (j = 0; j < i; j++)
		alias[j] = cmd[j];
	alias[j] = '\0';
	if (get_alias(alias) != NULL)
	{
		free(alias);
		return (1);
	}
	free(alias);
	return (0);
}


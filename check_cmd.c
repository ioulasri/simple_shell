#include "shell.h"

/**
 * check_cmd - checks if a command exits
 * @cmd: command to check
 * Return: 1 if exits, 0 if not
 */

int check_cmd(char *cmd)
{
	char *path = NULL;
	char *path_copy = NULL;
	char *token = NULL;
	char *cmd_path = NULL;
	struct stat st;

	if (cmd == NULL)
		return (0);
	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
			return (1);
		return (0);
	}
	path = getenv("PATH");
	path_copy = _strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		cmd_path = _strcat(token, "/");
		cmd_path = _strcat(cmd_path, cmd);
		if (stat(cmd_path, &st) == 0)
		{
			free(path_copy);
			free(cmd_path);
			return (1);
		}
		token = strtok(NULL, ":");
		free(cmd_path);
	}
	free(path_copy);
	return (0);
}

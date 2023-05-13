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
	int found = 0;

	if (cmd == NULL)
		return (0);
	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
			return (1);
		return (0);
	}
	path = getenv("PATH");
	if (path == NULL)
		return (0);
	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (0);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		cmd_path = _strcat(token, "/");
		cmd_path = _strcat(cmd_path, cmd);
		if (stat(cmd_path, &st) == 0)
			found = 1;
		free(cmd_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (found);
}

#include "shell.h"

/**
 * get_path - gets the path of a command
 * @cmd: command to get the path of
 * @tokens: tokens
 * @env: environment variables
 * Return: path of the command
 */

char *get_path(char *cmd)
{
	char *path = NULL;
	char *path_copy = NULL;
	char *token = NULL;
	char *cmd_path = NULL;
	struct stat st;

	if (cmd == NULL)
		return (NULL);
	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (NULL);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		cmd_path = _strcatpath(token, "/");
		cmd_path = _strcatpath(cmd_path, cmd);
		if (stat(cmd_path, &st) == 0)
		{
			free(path_copy);
			return (cmd_path);
		}
		token = strtok(NULL, ":");
		free(cmd_path);
	}
	free(path_copy);
	return (NULL);
}

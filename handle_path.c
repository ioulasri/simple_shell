#include "shell.h"

/**
 * get_path - gets the path of a command
 * @cmd: command to get the path of
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
            return (cmd_path);
        }
        token = strtok(NULL, ":");
        free(cmd_path);
    }
    free(path_copy);
    return (NULL);
}

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
    char *cmd_path = NULL;
    struct stat st;

    if (cmd == NULL)
        return NULL;
    if (cmd[0] == '/')
    {
        if (stat(cmd, &st) == 0)
            return cmd;
        return NULL;
    }
    path = getenv("PATH");
    if (path == NULL)
        return NULL;
    path_copy = _strdup(path);
    if (path_copy == NULL)
        return NULL;
    cmd_path = search_path(cmd, path_copy);
    free(path_copy);
    return cmd_path;
}

/**
 * search_path - searches the PATH environment variable for a command
 * @cmd: command to search for
 * @path: PATH environment variable
 * Return: path of the command, or NULL if not found
 */
char *search_path(char *cmd, char *path)
{
    char *token = NULL;
    char *cmd_path = NULL;

    token = strtok(path, ":");
    while (token != NULL)
    {
        cmd_path = build_cmd_path(cmd, token);
        if (cmd_path != NULL && file_exists(cmd_path))
            return cmd_path;
        free(cmd_path);
        token = strtok(NULL, ":");
    }
    return NULL;
}

/**
 * build_cmd_path - builds the full path of a command given a directory and command name
 * @cmd: command name
 * @dir: directory to search in
 * Return: full path of the command
 */
char *build_cmd_path(char *cmd, char *dir)
{
    char *cmd_path = NULL;
    size_t dir_len = 0, cmd_len = 0;

    if (dir == NULL || cmd == NULL)
        return NULL;

    dir_len = strlen(dir);
    cmd_len = strlen(cmd);
    cmd_path = malloc(dir_len + cmd_len + 2);
    if (cmd_path == NULL)
        return NULL;
    strcpy(cmd_path, dir);
    strcat(cmd_path, "/");
    strcat(cmd_path, cmd);

    return cmd_path;
}

/**
 * file_exists - checks if a file exists
 * @path: path of the file to check
 * Return: 1 if the file exists, 0 otherwise
 */
int file_exists(char *path)
{
    struct stat st;
    if (stat(path, &st) == 0)
        return 1;
    return 0;
}

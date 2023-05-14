#include "shell.h"

/**
 * _getenv - gets an environment variable
 * @name: name of the variable
 * Return: pointer to the variable, NULL if not found
 */

char *_getenv(const char *name)
{
    int i = 0, j = 0;

    while (environ[i] != NULL)
    {
        while (environ[i][j] != '=')
            j++;
        if (_strncmp(environ[i], (char *)name, j) == 0)
            return (environ[i] + j + 1);
        i++;
        j = 0;
    }
    return (NULL);
}

/**
 * _setenv - sets an environment variable
 * @name: name of the variable
 * @value: value of the variable
 * @overwrite: overwrite flag
 * Return: 0 on success, -1 on failure
 */

int _setenv(char *name, char *value, int overwrite)
{
    int i = 0, j = 0, k = 0;
    char *new_var = NULL;
    char **env = NULL;

    env = environ;
    while (env[i] != NULL)
    {
        while (env[i][j] != '=')
            j++;
        if (_strncmp(env[i], (char *)name, j) == 0)
        {
            if (overwrite == 1)
            {
                new_var = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
                if (new_var == NULL)
                    return (-1);
                for (k = 0; k < j; k++)
                    new_var[k] = env[i][k];
                new_var[k] = '=';
                k++;
                for (j = 0; value[j] != '\0'; j++, k++)
                    new_var[k] = value[j];
                new_var[k] = '\0';
                env[i] = new_var;
                return (0);
            }
            return (0);
        }
        i++;
        j = 0;
    }
    new_var = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
    if (new_var == NULL)
        return (-1);
    for (k = 0; name[k] != '\0'; k++)
        new_var[k] = name[k];
    new_var[k] = '=';
    k++;
    for (j = 0; value[j] != '\0'; j++, k++)
        new_var[k] = value[j];
    new_var[k] = '\0';
    env[i] = new_var;
    env[i + 1] = NULL;
    return (0);
}

/**
 * _unsetenv - unsets an environment variable
 * @name: name of the variable
 * Return: 0 on success, -1 on failure
 */

int _unsetenv(const char *name)
{
    int i = 0, j = 0, k = 0;
    char **env = NULL, *new_var = NULL;

    env = environ;
    while (env[i] != NULL)
    {
        while (env[i][j] != '=')
            j++;
        if (_strncmp(env[i], (char *)name, j) == 0)
        {
            new_var = malloc(sizeof(char) * (_constcharlen(name) + 2));
            if (new_var == NULL)
                return (-1);
            for (k = 0; name[k] != '\0'; k++)
                new_var[k] = name[k];
            new_var[k] = '=';
            new_var[k + 1] = '\0';
            env[i] = new_var;
            return (0);
        }
        i++;
        j = 0;
    }
    return (0);
}

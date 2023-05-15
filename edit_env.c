#include "shell.h"

/**
 * _getenv - gets an environment variable
 * @name: name of the variable
 * Return: pointer to the variable, NULL if not found
 */

char *_getenv(char *key)
{
	unsigned int i = 0;
	char *path;
	char **env;
	int count = 0, j = 0;

	while (environ[count])
		count++;

	env = malloc(sizeof(char *) * (count + 1));

	for (j = 0; j < count; j++)
		env[j] = _strdup(environ[j]);

	env[count] = NULL;

	while (env[i])
	{
		path = strtok(env[i], "=");
		if (_strcmp(key, env[i]) == 0)
		{
			path = strtok(NULL, "\n");
			return(path);
		}
		i++;
	}
	return (NULL);
}

int len_env(char **env)
{
	int i = 0;

	while (env[i])
		i++;
	return (i);
}

/**
 * _setenv - sets an environment variable
 * @name: name of the variable
 * @value: value of the variable
 * @overwrite: overwrite flag
 * Return: 0 on success, -1 on failure
 */

int _setenv(char *key, char *value, int overwrite)
{
	char *new_token;
	size_t len_key, len_value;
	int len_environ, i = 0, found = 0;
	char **new_environ;

	if (key == NULL || value == NULL)
		return (-1);

	if (_getenv(key) && overwrite == 0)
		return (0);

	len_key = _strlen(key);
	len_value = _strlen(value);
	new_token = malloc(sizeof(char) * (len_value + len_key + 2));

	_strcpy(new_token, key);
	_strcat(new_token, "=");
	_strcat(new_token, value);
	new_token[len_key + len_value + 1] = '\0';

	len_environ = len_env(environ);
	if (_getenv(key))
		new_environ = malloc(sizeof(char *) * len_environ);
	else
		new_environ = malloc(sizeof(char *) * len_environ + 1);

	while (environ[i])
	{
		if (_strncmp(environ[i], key, len_key) == 0)
		{
			new_environ[i] = _strdup(new_token);
			found = 1;
		}
		else
			new_environ[i] = environ[i];
		i++;
	}
	if (found == 0)
	{
		new_environ[i] = _strdup(new_token);
		new_environ[i + 1] = NULL;
	}
	else
		new_environ[i] = NULL;
	environ = new_environ;
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

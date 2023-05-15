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
	int i = 0, j = 0, k = 0;
	char *new_var = NULL;
	char **env = NULL;

	env = environ;
	while (env[i] != NULL)
	{
		while (env[i][j] != '=')
			j++;
		if (_strncmp(env[i], (char *)key, j) == 0)
		{
			if (overwrite == 1)
			{
				new_var = malloc(sizeof(char) * (_strlen(key) + _strlen(value) + 2));
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
	new_var = malloc(sizeof(char) * (_strlen(key) + _strlen(value) + 2));
	if (new_var == NULL)
		return (-1);
	for (k = 0; key[k] != '\0'; k++)
		new_var[k] = key[k];
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

int _unsetenv(char *key)
{
	int i = 0, j = 0, k = 0;
	char **env = NULL;

	env = environ;
	while (env[i] != NULL)
	{
		while (env[i][j] != '=')
			j++;
		if (_strncmp(env[i], (char *)key, j) == 0)
		{
			for (k = i; env[k] != NULL; k++)
				env[k] = env[k + 1];
			return (0);
		}
		i++;
		j = 0;
	}
	return (-1);
}

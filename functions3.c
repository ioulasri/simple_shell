#include "main.h"

/**
 * _setenv - sets an environment variable
 * @key: key of the environment variable
 * @value: value of the environment variable
 * @overwrite: overwrite flag
 * Return: 0 on success, -1 on failure
 */

int _setenv(char *key, char *value, int overwrite)
{
	int i = 0, j = 0, len_key = 0, len_value = 0;
	char **env = NULL;

	env = environ;
	if (key == NULL || value == NULL)
		return (-1);
	len_key = _strlen(key);
	len_value = _strlen(value);
	while (env[i] != NULL)
	{
		while (env[i][j] != '=')
			j++;
		if (_strncmp(env[i], (char *)key, j) == 0)
		{
			if (overwrite == 1)
			{
				env[i] = malloc(sizeof(char) * (len_key + len_value + 2));
				_strcpy(env[i], key);
				_strcat(env[i], "=");
				_strcat(env[i], value);
				return (0);
			}
			return (0);
		}
		i++;
		j = 0;
	}
	env[i] = malloc(sizeof(char) * (len_key + len_value + 2));
	_strcpy(env[i], key);
	_strcat(env[i], "=");
	_strcat(env[i], value);
	env[i + 1] = NULL;
	return (0);
}

/**
 * _unsetenv - unsets an environment variable
 * @key: name of the variable
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

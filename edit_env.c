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



#include "shell.h"

/**
 * check_alias - checks if a command is an alias
 * @cmd: command to check
 * Return: 1 if alias, 0 if not
 */

int check_alias(char *cmd)
{
	int i = 0;
	int j = 0;
	int len = 0;
	char *alias = NULL;

	if (cmd == NULL)
		return (0);
	len = _strlen(cmd);
	for (i = 0; i < len; i++)
	{
		if (cmd[i] == '=')
			break;
	}
	alias = malloc(sizeof(char) * (i + 1));
	if (alias == NULL)
		return (0);
	for (j = 0; j < i; j++)
		alias[j] = cmd[j];
	alias[j] = '\0';
	if (get_alias(alias) != NULL)
	{
		free(alias);
		return (1);
	}
	free(alias);
	return (0);
}

/**
 * get_alias - gets an alias
 * @name: name of the alias
 * Return: pointer to the alias, NULL if not found
 */

char *get_alias(const char *name)
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
 * set_alias - sets an alias
 * @name: name of the alias
 * @value: value of the alias
 * @overwrite: overwrite flag
 * Return: 0 on success, -1 on failure
 */

int set_alias(char *name, char *value, int overwrite)
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

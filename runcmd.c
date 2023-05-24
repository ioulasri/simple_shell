#include "main.h"

/**
 * execute - executes a command
 * @tokens: array of tokens
 * @argv: array of arguments
 * @env: array of environment variables
 * Return: 0 on success, 1 on failure
 */

int execute(char **tokens, char **argv, char **env)
{
	char *command = NULL;
	pid_t child_pid = 0;
	int status = 0;

	if (builtins(tokens, argv, env) == 0)
	{
		get_last_exit(1, 0);
		return (0);
	}
	command = get_path(tokens[0]);
	if (command == NULL)
	{
		perror(argv[0]);
		get_last_exit(1, 127);
		return (1);
	}
	if (!access(command, X_OK))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
			free(command);
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(command, tokens, env) == -1)
			{
				perror(argv[0]);
				free(command);
				exit(1);
			}
		}
		else
			wait(&status);
		get_last_exit(1, 0);
		free(command);
	}
	else
	{
		perror(argv[0]);
		get_last_exit(1, 126);
	}
	return (status);
}

/**
 * get_last_exit - gets the last exit code
 * @action: 0 to get, 1 to set
 * @status: exit code
 * Return: last exit code
 */

int get_last_exit(int action, int status)
{
	static int last_exit = 0;

	if (action == 1)
		last_exit = status;
	return (last_exit);
}

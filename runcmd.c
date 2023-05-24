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
		ex_status(0);
		return (0);
	}
	command = get_path(tokens[0]);
	if (command == NULL)
	{
		perror(argv[0]);
		ex_status(127);
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
		ex_status(status);
		free(command);
	}
	else
	{
		perror(argv[0]);
		free(command);
		ex_status(126);
		return (1);
	}
	return (status);
}

/**
 * ex_status - gets the exit status of the last command
 * @status: exit status
 * Return: exit status
 */

int ex_status(int status)
{
	static int ex = 0;
	int prev = 0;

	prev = ex;
	ex = status;
	return (prev);
}

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
		return (0);
	command = get_path(tokens[0]);
	if (command == NULL)
		return (1);
	if (!access(command, X_OK))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
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
	}
	return (status);
}

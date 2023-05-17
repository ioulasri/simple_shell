#include "shell.h"

/**
 * run_cmd - runs a command
 * @tokens: tokens
 * @env: environment variables
 * @av: argv
 * Return: 0 on success, 1 on failure.
 */

int run_cmd(char **tokens, char **env, char **av)
{
	int is_built_in = 0, cmd_exits = 0;
	char *path = NULL;
	int status = 0;
	pid_t pid = 0;

	is_built_in = builtins(tokens, env);
	cmd_exits = check_cmd(tokens[0]);
	if (is_built_in == 0 && cmd_exits == 1)
	{
		path = get_path(tokens[0]);
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			free(path);
			return (-1);
		}
		if (pid == 0)
		{
			if (execve(path, tokens, env) == -1)
			{
				perror("Error");
				free(path);
				exit(1);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				ex_status = WEXITSTATUS(status);
		}
		free(path);
	}
	if (is_built_in == 0 && cmd_exits == 0)
	{
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
		write(STDERR_FILENO, ": not found\n", 12);
	}
	return (0);
}

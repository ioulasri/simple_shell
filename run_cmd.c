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
	struct stat st;

	is_built_in = builtins(tokens, env);
	cmd_exits = check_cmd(tokens[0]);
	if (is_built_in == 0 && cmd_exits == 1)
	{
		if (stat(tokens[0], &st) == 0)
			path = _strdup(tokens[0]);
		else
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
			{
				ex_status = WEXITSTATUS(status);
				_setenv("?", _itoa(ex_status), 1);
			}
		}
		free(path);
	}
	if (is_built_in == 0 && cmd_exits == 0)
	{
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
		write(STDERR_FILENO, ": Command was not found\n", 24);
		ex_status = 127;
		_setenv("?", _itoa(ex_status), 1);
	}
	return (0);
}

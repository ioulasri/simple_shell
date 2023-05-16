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
			free_array(tokens);
			return (-1);
		}
		if (pid == 0)
		{
			if (execve(path, tokens, env) == -1)
			{
				free(tokens);
				return (-1);
			}
		}
		else
			wait(&ex_status);
	}
	if (is_built_in == 0 && cmd_exits == 0)
		perror(av[0]);
	return (0);
}

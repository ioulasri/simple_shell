#include "main.h"

/**
 * main - starting point of the program
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: array of environment variables
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char **argv, char **env)
{
	char *line = NULL, **tokens = NULL;
	size_t len = 0;
	ssize_t read = 0;
	int status = 0;

	(void)argc;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		tokens = tokenize(line);
		if (tokens == NULL)
			continue;
		status = execute(tokens, argv, env);
		free(tokens);
	}
	free(line);
	return (status);
}

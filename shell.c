#include "shell.h"

/**
 * main - main function of the shell
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	char *buf = NULL;
	size_t buf_size = 0;
	int n_characters = 0;
	int shell = 1;
	(void)ac;

	while (shell)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		signal(SIGINT, sigint_handler);
		n_characters = getline(&buf, &buf_size, stdin);
		if (n_characters == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (n_characters > 1)
			buf[n_characters - 1] = '\0';
		if (buf[0] == '\n')
			continue;
		handle_input(buf, env, av);
		buf_size = 0;
		buf = NULL;
	}
	return (0);
}

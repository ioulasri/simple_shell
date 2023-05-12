#include "shell.h"

/**
 * handle_input - handles the input from the user
 * @buf: buffer to store the input
 * @env: environment variables
 */

void handle_input(char *buf, char **env, char **av)
{
    char **tokens = NULL;

    if (buf == NULL)
        return;
    tokens = tokenize(buf);
    if (tokens == NULL)
    {
        free(buf);
        return;
    }
    if (tokens[0] == NULL)
    {
        free(buf);
        free(tokens);
        return;
    }
    if (run_cmd(tokens, env, av) == -1)
    {
        free(buf);
        free(tokens);
        return;
    }
    free(buf);
    free(tokens);
    return;
}

#include "shell.h"

/**
 * my_cd - changes the current working directory
 * @args: arguments
 */

void my_cd(char **args)
{
    char **directories = NULL;
    char *oldpwd = NULL;
    char *pwd = NULL;
    char *home = NULL;

    if (args[1] == NULL)
    {
        home = getenv("HOME");
        if (home == NULL)
        {
            write(STDERR_FILENO, "cd: HOME not set\n", 17);
            return;
        }
        directories = malloc(sizeof(char *) * 2);
        if (directories == NULL)
            return;
        directories[0] = home;
        directories[1] = NULL;
    }
    else if (_strncmp(args[1], "-", 1) == 0)
    {
        oldpwd = getenv("OLDPWD");
        if (oldpwd == NULL)
        {
            write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
            return;
        }
        directories = malloc(sizeof(char *) * 2);
        if (directories == NULL)
            return;
        directories[0] = oldpwd;
        directories[1] = NULL;
    }
    else
    {
        directories = malloc(sizeof(char *) * 2);
        if (directories == NULL)
            return;
        directories[0] = args[1];
        directories[1] = NULL;
    }
    if (chdir(directories[0]) == -1)
    {
        print_error(args[0], 0, args[1], "can't cd to ");
        return;
    }
    else
    {
        oldpwd = getenv("PWD");
        pwd = getcwd(NULL, 0);
        setenv("OLDPWD", oldpwd, 1);
        setenv("PWD", pwd, 1);
        free(pwd);
    }
    free(directories);
}

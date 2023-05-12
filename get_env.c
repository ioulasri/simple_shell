#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 * Return: value of the environment variable
 */

char *_getenv(const char *name) {
    extern char **environ; 
    int i = 0;
    while (environ[i] != NULL) {
        if (strncmp(name, environ[i], strlen(name)) == 0 && environ[i][strlen(name)] == '=') {
            return (&environ[i][strlen(name) + 1]); 
        }
        i++;
    }
    return NULL;
}

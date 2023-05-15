#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define READ_SIZE 1024
#define BUFSIZE 1024

int ex_status;
extern char **environ;

/* get_line.c */
ssize_t _getline(char **buffer, size_t *bufsize, int fd);

/* handle_input.c */
int handle_input(char *buf, char **env, char **av);
void sigint_handler(int signal);

/* split_string.c */
char **tokenize(char *buf);

/* handle_builtins.c */
int builtins(char **tokens, char **env);

/* functions1.c */
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *str1, char *str2, int n);
char *_strdup(char *str);
char *_strcatpath(char *dest, char *src);

/* functions2.c */
int _atoi(char *str);
char *_strcpy(char *dest, char *src);
char *_itoa(int num);
int _constcharlen(const char *str);
void print_error(char *av, int count, char *cmd, char *msg);

/* functions3.c */
char *_strchr(const char *s, int c);
char *_strtok(char *str, char *delim);
char *_strcat(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* free_array.c */
void free_array(char **array);

/* check_cmp.c */
int check_cmd(char *cmd);

/* get_path.c */
char *get_path(char *cmd);

/* run_cmd.c */
int run_cmd(char **tokens, char **env, char **av);

/* edit_env.c */
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *key);
int len_env(char **env);
char *_getenv(char *key);

/* my_cd.c */
void my_cd(char **args);

/* alias.c */
char *get_alias(const char *name);
int check_alias(char *cmd);
int set_alias(char *name, char *value, int overwrite);

/* handle_echo.c */
int handle_echo(char **tokens, int *status);
void handle_echo_args(char *tokens, int *status);
char *get__env(char *key);
char *to_upper(char *str);

#endif /* SHELL_H */

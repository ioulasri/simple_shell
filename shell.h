#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **environ;

/* handle_input.c */
int handle_input(char *buf, char **env, char **av);

/* split_string.c */
char **tokenize(char *buf);

/* handle_builtins.c */
int builtins(char **tokens, char **env);

/* functions1.c */
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *str1, char *str2, int n);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

/* functions2.c */
char *_getenv(const char *name);
char *_strtok(char *str, char *delim);
int _atoi(char *str);
char *_strcpy(char *dest, char *src);
char *_itoa(int num);

/* functions3.c */
void print_error(char *av, int count, char *cmd, char *msg);

/* free_array.c */
void free_array(char **array);

/* check_cmp.c */
int check_cmd(char *cmd);

/* get_path.c */
char *get_path(char *cmd);

/* run_cmd.c */
int run_cmd(char **tokens, char **env, char **av);

#endif /* SHELL_H */

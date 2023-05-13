#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define READ_SIZE 1024

char **environ;
/* get_line.c */

typedef struct list_s
{
    char *buffer;
    char **args;
    int status;
    pid_t pid;
    struct list_s *next;
} list_t;

char *get_line(char **buffer, size_t *buffer_size, int fd);
int found_newline(char *buf);
list_t *add_node_end(list_t **head);
void read_and_stash(int fd, list_t **head, char *buffer);
void extract_line(list_t **head, char **buf, char **line);
void generate_line(list_t **head, char *buf, char **line);
void clean_stash(list_t **head);
void free_stash(list_t **head);


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
int _atoi(char *str);
char *_strcpy(char *dest, char *src);
char *_itoa(int num);

/* functions3.c */
char *_strchr(const char *s, int c);
char *_strtok(char *str, char *delim);

/* free_array.c */
void free_array(char **array);

/* check_cmp.c */
int check_cmd(char *cmd);

/* get_path.c */
char *get_path(char *cmd);

/* run_cmd.c */
int run_cmd(char **tokens, char **env, char **av);



#endif /* SHELL_H */

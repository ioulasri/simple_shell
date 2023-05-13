#include "shell.h"

/**
 * found_newline - checks if a string has a newline character
 * @str: string to check
 * Return: 1 if found, 0 if not
 */

int found_newline(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the head of the list
 * Return: address of the new element, or NULL if it failed
 */

list_t *add_node_end(list_t **head)
{
    list_t *new_node = NULL, *temp = NULL;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);
    new_node->next = NULL;
    new_node->buffer = NULL;
    new_node->args = NULL;
    new_node->status = 0;
    new_node->pid = 0;
    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    return (new_node);
}


/**
 * read_and_stash - reads a line from stdin and stores it in a list
 * @fd: file descriptor to read from
 * @head: pointer to the head of the list
 * @buffer: buffer to store the line
 */

void read_and_stash(int fd, list_t **head, char *buffer)
{
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    char *temp = NULL;

    while (1)
    {
        i = read(fd, buffer, READ_SIZE);
        if (i == 0)
            break;
        if (i == -1)
        {
            perror("read");
            exit(1);
        }
        buffer[i] = '\0';
        if (found_newline(buffer))
        {
            while (buffer[j] != '\n')
                j++;
            temp = malloc(sizeof(char) * (j + 1));
            if (temp == NULL)
                exit(1);
            for (k = 0; k < j; k++)
                temp[k] = buffer[k];
            temp[k] = '\0';
            add_node_end(head)->buffer = temp;
            l = 0;
            for (k = j + 1; buffer[k] != '\0'; k++)
                l++;
            temp = malloc(sizeof(char) * (l + 1));
            if (temp == NULL)
                exit(1);
            for (k = j + 1, m = 0; buffer[k] != '\0'; k++, m++)
                temp[m] = buffer[k];
            temp[m] = '\0';
            lseek(fd, -l - 1, SEEK_CUR);
            write(fd, temp, l);
            free(temp);
            break;
        }
        add_node_end(head)->buffer = _strdup(buffer);
    }
}

/**
 * generate_line - generates a line from a list
 * @head: pointer to the head of the list
 * @buffer: buffer to store the line
 * @line: line string to be generated
 */

void generate_line(list_t **head, char *buffer, char **line)
{
    list_t *temp = NULL;
    int i = 0, j = 0, k = 0, l = 0;

    temp = *head;
    while (temp != NULL)
    {
        i = _strlen(temp->buffer);
        for (j = 0; j < i; j++, k++)
            buffer[k] = temp->buffer[j];
        temp = temp->next;
    }
    buffer[k] = '\0';
    i = _strlen(buffer);
    *line = malloc(sizeof(char) * (i + 1));
    if (*line == NULL)
        exit(1);
    for (j = 0; j < i; j++, l++)
        (*line)[l] = buffer[j];
    (*line)[l] = '\0';
}

/**
 * clean_stash - frees the list and cleans the stash
 * @head: pointer to the head of the list
 */

void clean_stash(list_t **head)
{
    list_t *temp = NULL;

    temp = *head;
    while (temp != NULL)
    {
        *head = temp->next;
        free(temp->buffer);
        free(temp->args);
        free(temp);
        temp = *head;
    }
}

/**
 * get_line - reads a line from stdin
 * @fd: file descriptor to read from
 * @buffer: buffer to store the line
 * @buffer_size: size of the buffer
 * Return: the line read
 */

char *get_line(char **buffer, size_t *buffer_size, int fd)
{
    static list_t *head;
    char *line = NULL;

    if (buffer == NULL || buffer_size == NULL)
        return (NULL);
    if (*buffer == NULL)
    {
        *buffer_size = READ_SIZE;
        *buffer = malloc(sizeof(char) * (*buffer_size + 1));
        if (*buffer == NULL)
            exit(1);
    }
    if (head == NULL)
        read_and_stash(fd, &head, *buffer);
    generate_line(&head, *buffer, &line);
    clean_stash(&head);
    return (line);
}

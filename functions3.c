#include "shell.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to be searched
 * @accept: string containing the characters to match
 * Return: pointer to the byte in s that matches one of the bytes in accept
 */

char *_strpbrk(char *s, char *accept)
{
	int i = 0, j = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				return (s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/**
 * _strtok - tokenizes a string
 * @str: string to be tokenized
 * @delim: delimiter
 * Return: pointer to the tokenized string
 */

char *_strtok(char *str, char *delim)
{
	static char *token;
	static char *next_token;
	char *delim_ptr = NULL;

	if (str != NULL)
		token = str;
	else
		token = next_token;
	if (token == NULL)
		return (NULL);
	delim_ptr = _strpbrk(token, delim);
	if (delim_ptr != NULL)
	{
		*delim_ptr = '\0';
		next_token = delim_ptr + 1;
	}
	else
		next_token = NULL;
	return (token);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: size of the allocated space for ptr
 * @new_size: new size of the new memory block
 * Return: pointer to the new memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;
    unsigned int i;

    if (new_size == old_size)
        return (ptr);

    if (ptr == NULL)
        return (malloc(new_size));

    if (new_size == 0 && ptr != NULL)
        return (NULL);

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return (NULL);

    for (i = 0; i < old_size && i < new_size; i++)
        new_ptr[i] = ((char *)ptr)[i];

    return (new_ptr);
}

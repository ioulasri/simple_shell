#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 if strings are equal, -1 if not
 */

int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}

/**
 * _strncmp - compares two strings
 * @str1: first string
 * @str2: second string
 * @n: number of bytes to compare
 * Return: 0 if strings are equal, -1 if not
 */

int _strncmp(char *str1, char *str2, int n)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && i < n)
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	if (i == n)
		return (0);
	return (-1);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int i = 0;
	char *dup = NULL;

	if (str == NULL)
		return (NULL);
	dup = malloc(sizeof(char) * (_strlen(str) + 1));
	if (dup == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
    if (dest == NULL || src == NULL)
        return NULL;

    size_t src_len, dest_len;
	char *new_str;

	dest_len = strlen(dest);
    src_len = strlen(src);

    new_str = malloc(dest_len + src_len + 1);

    if (new_str == NULL)
        return NULL;

    _strcpy(new_str, dest);
    _strcpy(new_str + dest_len, src);

    return new_str;
}
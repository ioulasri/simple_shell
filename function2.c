#include "main.h"


/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to the copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
 * ffree - frees a double pointer
 * @ptr: double pointer to be freed
 * Return: void
 */

void ffree(char **ptr)
{
	char **temp = ptr;

	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
	if (temp != NULL)
		free(temp);
	ptr = NULL;
}

/**
 * p_free - frees a pointer
 * @ptr: pointer to be freed
 * Return: void
 */

void p_free(char *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}

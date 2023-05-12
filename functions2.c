#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @str: string to be converted
 * Return: integer value of the string
 */

int _atoi(char *str)
{
    int i = 0, sign = 1, num = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '-')
            sign *= -1;
        if (str[i] >= '0' && str[i] <= '9')
            num = num * 10 + (str[i] - '0');
        if (str[i] == ';')
            break;
        i++;
    }
    return (num * sign);
}

/**
 * _itoa - converts an integer to a string
 * @num: integer to be converted
 * Return: pointer to the converted string
 */

char *_itoa(int num)
{
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    char *str = NULL;

    if (num == 0)
    {
        str = malloc(sizeof(char) * 2);
        if (str == NULL)
            return (NULL);
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    if (num < 0)
        l = 1;
    m = num;
    while (m != 0)
    {
        m /= 10;
        i++;
    }
    str = malloc(sizeof(char) * (i + 1 + l));
    if (str == NULL)
        return (NULL);
    if (l == 1)
        str[0] = '-';
    for (j = i - 1 + l; j >= l; j--)
    {
        k = num % 10;
        if (k < 0)
            k *= -1;
        str[j] = k + '0';
        num /= 10;
    }
    str[i + l] = '\0';
    return (str);
}

/**
 * _strtok - tokenizes a string
 * @str: string to be tokenized
 * @delim: delimiter
 * Return: pointer to the tokenized string
 */

char *_strtok(char *str, char *delim)
{
    static char *token = NULL;
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    char *tok = NULL;

    if (str != NULL)
        token = str;
    if (token == NULL)
        return (NULL);
    while (token[i] != '\0')
    {
        while (delim[j] != '\0')
        {
            if (token[i] == delim[j])
            {
                l++;
                break;
            }
            j++;
        }
        if (l == 0)
            m++;
        if (l > 0 && m > 0)
            break;
        i++;
        j = 0;
    }
    if (token[i] == '\0')
    {
        token = NULL;
        return (NULL);
    }
    tok = malloc(sizeof(char) * (m + 1));
    if (tok == NULL)
        return (NULL);
    while (k < m)
    {
        tok[k] = token[k];
        k++;
    }
    tok[k] = '\0';
    token += m + 1;
    return (tok);
}

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

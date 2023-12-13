#include "shell.h"

/**
 * _strdup - duplicate string
 * @str: string to duplicate
 * Return: new string
 */

char *_strdup(const char *str)
{
    char *ptr;
    int i, len = 0;

    if (str == NULL)
        return (NULL);
    while (*str != '\0')
    {
        len++;
        str++;
    }
    str = str - len;
    ptr = malloc(sizeof(char) * (len + 1));
    if (ptr == NULL)
        return (NULL);
    for (i = 0; i <= len; i++)
        ptr[i] = str[i];
    return (ptr);
}

/**
 * _strcmp - compare two strings:
 * @s1: string 1
 * @s2: string 2
 * Return: cmp
 */

int _strcmp(char *s1, char *s2)
{
    int cmp;

    cmp = (int)*s1 - (int)*s2;
    while (*s1)
    {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
        cmp = (int)*s1 - (int)*s2;
    }
    return(cmp);
}

/**
 * _strlen - len of a string
 * @s: string 
 * Return: len
 */

int _strlen(char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return (len);
}

/**
 * _strcat - concat two string
 * @dest: destination
 * @src: source
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
    char *p = dest;

    while (*p)
        p++;

    while (*src)
    {
        *p = *src;
        p++;
        src++;
    }
    *p = *src;
    return (dest);
}

/**
 * _strcpy - copy a string into another
 * @dest: destination
 * @src: source
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}

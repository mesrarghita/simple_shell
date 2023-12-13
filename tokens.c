#include "shell.h"

/**
 * _tokens - tokenize a string
 * @buffer: string
 * Return: command split
 */

char **_tokens(char *buffer)
{
    char *token = NULL, *tmp = NULL;
    char **cmd = NULL;
    int count1 = 0, count2 = 0;
    if (!buffer)
        return(NULL);
    tmp = _strdup(buffer);
    token = strtok(tmp, DELIM);
    if (token == NULL)
    {
        free(buffer), buffer = NULL;
        free(tmp), tmp = NULL;
        return (NULL);
    }
    while (token)
    {
        count1++;
        token = strtok(NULL, DELIM);
    }
    free(tmp), tmp = NULL;
    cmd = malloc(sizeof(char *) * (count1 + 1));
    if (!cmd)
    {
        free(buffer), buffer = NULL;
        return (NULL);
    }
    token = strtok(buffer, DELIM);
    while (token)
    {
        cmd[count2] = _strdup(token);
        token = strtok(NULL, DELIM);
        count2++;
    }
    free(buffer), buffer = NULL;
    cmd[count1] = NULL;
    return(cmd);
}

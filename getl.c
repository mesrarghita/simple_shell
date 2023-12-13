#include "shell.h"
/**
 * _getline - input from user
 * Return: the input
 */

char *_getline(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t n;

    if (isatty(STDIN_FILENO))
        write(STDERR_FILENO, "$ ", 2);
        
    n = getline(&line, &len, stdin);
    if (n == -1)
    {
        free(line);
        return (NULL);
    }

    return (line);
}

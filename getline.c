#include "shell.h"

/**
 * get_input - to get input from user
 *
 * Return: input
 */

char *get_input(void)
{
	char* linep = NULL;
	size_t linecapp = 0;
	ssize_t char_len;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);

	char_len = getline(&linep, &linecapp, stdin);

	if (char_len == -1)
	{
		free(linep);
		return (NULL);
	}

	return (linep);
}

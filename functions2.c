#include "shell.h"

/**
 * free_arr - free and array 
 * @arr: pointed to an array
 * 
 */

void free_arr(char **arr)
{
    int i = 0;

    if (!arr)
        return;
    
    for (i = 0; arr[i]; i++)
    {
        free(arr[i]);
        arr[i] = NULL;
    }

    free(arr), arr = NULL;
}

/**
 * print_e - print an error 
 * @name: error name
 * @cmd: command
 * @idx: index
 * Return: the index
 */
void print_e(char *name, char* cmd, int idx)
{
   char *index, mssg[] = ": not found\n";

    index = _itoa(idx);

    write(STDERR_FILENO, name, _strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, _strlen(index));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, mssg, _strlen(mssg));

    free(index);
    
}

/**
 * _itao - int to ascii
 * @n: int type input
 * return: stdrup of buffer
 */

char *_itoa(int n)
{
    char buffer[20];
    int i = 0;

    if (n == 0)
        buffer[i++] = '0';
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }

    buffer[i] = '\0';
    reverse_str(buffer, i);

    return(_strdup(buffer));
}

/**
 * reverse_str - reverse a string
 * @str: the string
 * @len: length
 */

void reverse_str(char *str, int len)
{
    char tmp;
    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        str++;
        end--;
    }
}

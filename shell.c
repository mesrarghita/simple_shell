#include "shell.h"

/**
 * main - main shell program
 * @arc: argument count
 * @argv: arguments 
 * Return: 0
 */

int main(int arc, char **argv)
{
        char *buffer = NULL;
        char **cmd = NULL;
        int status = 0, index = 0;
        
        (void)arc;

        while(1)
        {
                buffer = _getline();
                if (buffer == NULL)
                {
                        if (isatty(1))
                        {
                                write(1, "\n", 1);
                        }
                        return(status);
                }
                index++;

                cmd = _tokens(buffer);
                if (!cmd)
                        continue;

                status = _exec(cmd, argv, index);


        }
        return (0);
}

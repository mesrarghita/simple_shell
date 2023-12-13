#include "shell.h"

/**
 * _exec - execute a command
 * @cmd: command
 * @argv: arguments
 * @index: index
 * Return: status
 */


int _exec(char **cmd,char **argv, int index) 
{
    char *all_cmd;

    pid_t child_id;
    int s;

    all_cmd = _getp(cmd[0]);
    if (!all_cmd)
    {
        print_e(argv[0], cmd[0], index);
        free_arr(cmd);
        return(127);
    }
        
    child_id = fork();
    if (child_id == 0)
    {
        if(execve(all_cmd, cmd, environ) == -1)
        {
            free(all_cmd), all_cmd = NULL;

            free_arr(cmd);
        }
    }
    else
    {
        waitpid(child_id, &s, 0);
        free_arr(cmd);
        free(all_cmd), all_cmd = NULL;
    }

    return (WEXITSTATUS(s));
}

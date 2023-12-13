#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_getline();
char **_tokens(char *line);
int _exec(char **command, char **argv, int idx);
char *_getv(char *variable);
char *_getp(char *command);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_itoa(int idx);
void reverse_str(char *str, int len);

#define DELIM " \t\n"
extern char **environ;

void free_arr(char **arr);
void prtint_e(char name, char cmd, int idx);

#endif

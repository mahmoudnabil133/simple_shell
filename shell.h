#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
extern char **environ;
char *read_line(void);
char **splitString(char *str);
void _printf(char *str);
void check_start(char **comands);
void free_arr(char **arr);
char *get_path(char *comand);
char *_getenv(char *name);
void env(char **comands);
int shell_exec(char **comands, char **argv);
/*string functions*/
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, const char *src);
char *_strdup(char *s);
/*-----------------------------------------*/

#endif

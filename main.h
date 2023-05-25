#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
extern char **environ;
void run(void);
void exec_cmd(char **argv);
void _execve(char **argv);
char **toknize(char *lineptr);
int check_builtin(char **argv);
void _builtin(char **argv);
void free_argv(char **argv);
char *_getenv(const char *key);
#endif
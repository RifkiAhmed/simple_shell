#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

int _strlen(char *s);
char *_strdup(char *str);
int _atoi(char *s);
char **tokenize(char *str, const char *delim);
void execut(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_argv(char **arv);

#endif
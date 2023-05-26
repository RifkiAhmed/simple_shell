#include "main.h"

/**
 * _builtin - execute bultin program
 * @argv: argument vector
 *
 * Return: void
 */
void _builtin(char **argv)
{
if (!argv || !argv[0])
{
return;
}
if (strcmp(argv[0], "exit") == 0)
{
exit(EXIT_SUCCESS);
}
else if (strcmp(argv[0], "cd") == 0)
{
_cd(argv);
}
else if (strcmp(argv[0], "env") == 0)
{
char **env;
ssize_t n;
for (env = environ; *env != NULL; env++)
{
n = strlen(*env);
if (write(STDOUT_FILENO, *env, n) != n || write(STDOUT_FILENO, "\n", 1) != 1)
{
perror("write");
break;
}
}
}
}

/**
 * toknize - thom argv function
 * @lineptr: user input
 *
 * Return: pointer of strings
 */
char **toknize(char *lineptr)
{
char **argv;
char *token;
int i = 0;

argv = malloc(258 * sizeof(char *));
token = strtok(lineptr, " \t\n");
while (token != NULL && i < 258)
{
argv[i++] = strdup(token);
token = strtok(NULL, " \t\n");
}
argv[i] = NULL;
return (argv);
}

/**
 * free_argv - Free argv pointer of pointer
 * @argv: arguments vector
 *
 * Return: void
 */
void free_argv(char **argv)
{
int i;
for (i = 0; argv[i]; i++)
{
free(argv[i]);
}
free(argv);
}

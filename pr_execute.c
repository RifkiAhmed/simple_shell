#include "main.h"

#define BUFF_SSIZE 4096
#define IMAX_ARGS 258

/**
 * run - run shell
 * 
 * Return: void
 */
void run(void)
{
char *lineptr = NULL;
char **argv;
size_t n = 0;
ssize_t chars_n;
while (1)
{
if (isatty(0))
write(STDOUT_FILENO, "$ ", 2);
chars_n = getline(&lineptr, &n, stdin);
if (chars_n == -1)
{
free(lineptr);
exit(0);
}
argv = toknize(lineptr);
if (!argv[0])
{
free_argv(argv);
continue;
}
if (check_builtin(argv))
{
_builtin(argv);
}
else
{
exec_cmd(argv);
}
free_argv(argv);
}
free(lineptr);
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
exit(0);
}
else if (strcmp(argv[0], "cd") == 0)
{
const char *di = argv[1] ? argv[1] : _getenv("HOME");
if (chdir(di) != 0)
{
perror("cd");
}
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
 * check - checks for bultin function
 * @argv: argument element
 * 
 * Return: 1 or 0
 */
int check_builtin(char **argv)
{
return (strcmp(argv[0], "exit") == 0 ||
strcmp(argv[0], "cd") == 0 ||
strcmp(argv[0], "env") == 0);
}
/**
 * toknize - thom argv function
 * @lineptr: user input
 * 
 * Return: pointer of strings
 */
char **toknize(char *lineptr)
{
char **argv = malloc(IMAX_ARGS * sizeof(char *));
char *token;
int i = 0;

token = strtok(lineptr, " \t\n");
while (token != NULL && i < IMAX_ARGS)
{
argv[i++] = strdup(token);
token = strtok(NULL, " \t\n");
}
argv[i] = NULL;
return (argv);
}
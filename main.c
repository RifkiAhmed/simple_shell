#include "main.h"

/**
 * main - run code
 * 
 * Return: 0
 */
int main(void)
{
char *lineptr = NULL, **argv;
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
if (strcmp(argv[0], "exit") == 0 ||
strcmp(argv[0], "cd") == 0 ||
strcmp(argv[0], "env") == 0)
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
return (0);
}
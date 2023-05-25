#include "main.h"

/**
 * exec_cmd - program execute
 * @argv: argumments vector
 *
 * Return: void
 */

void exec_cmd(char **argv)
{
pid_t pid = fork();

if (pid == 0)
{
_execve(argv);
exit(0);
}
else
{
waitpid(pid, NULL, 0);
}
}

/**
 * _execve - program execute
 * @argv: arguments vector
 *
 * Return: void
 */
void _execve(char **argv)
{
char *token, *path, *value, *command;
int i;

for (i = 0; argv[i]; i++)
{
command = argv[i];

if (access(command, X_OK) == 0)
{
execve(command, argv, environ);
}
value = _getenv("PATH");
token = strtok(value, ":");

while (token != NULL)
{
path = malloc(strlen(token) + strlen(command) + 2);
sprintf(path, "%s/%s", token, command);

if (access(path, X_OK) == 0)
{
execve(path, argv, environ);
}

free(path);
token = strtok(NULL, ":");
}
perror("./hsh");
}
}

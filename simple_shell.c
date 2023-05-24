#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - test code
 * @argc: arguments counter
 * @argv: array of string, each string is one of the arguments
 * @env: envirnment variables
 *
 * Return: 0
 */

int main()
{
	char *lineptr, **argv;
	size_t n;
	ssize_t chars;
	pid_t pid;

	n = 0;
	lineptr = NULL;
	while (1)
	{
		if (isatty(0))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		fflush(stdout);
		chars = getline(&lineptr, &n, stdin);

		if (chars == -1)
		{
			free(lineptr);
			return (-1);
		}

		argv = malloc(sizeof(char *) * 1024);
		argv[0] = strtok(lineptr, "\n");
		argv[1] = NULL;
		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("./hsh");
			}
		}
		else
		{
			wait(NULL);
		}
		free(argv);
	}
	return (0);
}

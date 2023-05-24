#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - test code
 * @argc: arguments counter
 * @argv: array of string, each string is one of the arguments
 * @env: envirnment variable
 *
 * Return: 0
 */

int main(int argc, char **argv, char **env)
{
	char *lineptr;
	size_t n;
	ssize_t chars;
	pid_t pid;

	(void)argc;
	n = 0;
	lineptr = NULL;
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		chars = getline(&lineptr, &n, stdin);

		if (chars == EOF)
		{
			free(argv);
			free(lineptr);
			exit(EXIT_SUCCESS);
		}

		argv = malloc(sizeof(char *) * 1024);
		argv[0] = strtok(lineptr, " \n\t\0");
		argv[1] = NULL;
		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				perror("./hsh");
			}
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}

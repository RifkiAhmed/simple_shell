#include "main.h"

/**
 * execute - executes a command
 * @lineptr: pointer
 * @argv: array of arguments
 */

void execute(char *lineptr, char **argv)
{

	int d, status;

	if (!argv || !argv[0])
	{
		free(lineptr);
		freearv(argv);
		return;
	}
	d = fork();
	if (d == -1)
	{
		perror("./hsh");
	}
	if (d == 0)
	{
		if(execve(argv[0], argv, environ) == -1)
		{
			freearv(argv);
			free(lineptr);
			perror("./hsh");
		}
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * freearv - frees the array of pointers arv
 *@arv: array of pointers
 */

void freearv(char **arv)
{
	int i;

	for (i = 0; arv[i] != NULL; i++)
		free(arv[i]);
	free(arv);
}

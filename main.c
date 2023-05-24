#include "main.h"

/**
 * f_handler - checks if ctrl-c is pressed
 * @sig: int
 */
void f_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}

/**
 * main - check code
 * 
 * Return: 0
 */

int main(void)
{
	char *lineptr = NULL, **argv;
	size_t n = 0;
	ssize_t chars = 0;

	signal(SIGINT, f_handler);
	while (chars != EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		chars = getline(&lineptr, &n, stdin);
		if (chars == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
				free(lineptr);
			}
			exit(0);
		}
		argv = malloc(sizeof(char *) * 2);
		argv[0] = strtok(lineptr, "\n");
		argv[1] = NULL;;
		execut(argv);
	}
	free(lineptr);
	free_argv(argv);
	return (0);
}

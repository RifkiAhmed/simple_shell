#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - test code
 * @ac: argument counter
 * @av: array of string, each string is one of the arguments
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *lineptr;
	size_t n = 0;
	int read_char;
	(void)ac;
	(void)av;

	while (1)
	{
		write(STDOUT_FILENO, "IA $: ", 6);

		read_char = getline(&lineptr, &n, stdin);
		if (read_char != -1)
			write(1, lineptr, read_char);
		else
			return (-1);
	}
	return (0);
}

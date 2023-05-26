#include "main.h"

/**
 * _cd - program change directory
 * @argv: argumments vector
 *
 * Return: void
 */

void _cd(char **argv)
{
if (argv[1] == NULL)
{
perror("./hsh");
return;
}


if (chdir(argv[1]) != 0)
{
perror("./hsh");
return;
}
}

/**
 * _exit - program exit shell
 * @argv: argumments vector
 *
 * Return: void
 */

void _exit(char **argv)
{
	if (argv[1] != NULL)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}


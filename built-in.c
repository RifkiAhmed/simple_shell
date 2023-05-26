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

/**
 * _setenv - program that initialize new environment variable,
 * or modify an existing one
 * @argv: argumments vector
 *
 * Return: void
 */

void _setenv(char **argv)
{
	if (argv[1] == NULL || argv[2] == NULL)
	{
		perror("./hsh");
		return;
	}
	setenv(argv[1], argv[2], 1);
}

/**
 * _unsetenv - Remove an environment variable
 * @argv: argumments vector
 *
 * Return: void
 */

void _unsetenv(char **argv) {
if (argv[1] == NULL) {
perror("./hsh");
return;
}


unsetenv(argv[1]);
}


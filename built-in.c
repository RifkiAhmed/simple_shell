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


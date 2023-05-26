#include "main.h"


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


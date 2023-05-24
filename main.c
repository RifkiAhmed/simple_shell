#include "main.h"

/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n$ ");
	}
}

/**
* _EOF - handles the End of File
* @len: return value of getline function
* @buff: buffer
 */
void _EOF(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * _isatty - verif if terminal
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("$ ");
}
/**
 * main - Shell
 * Return: 0 on success
 */

int main (void)
{
    ssize_t len = 0;
    char *buff = NULL, **arv;
    size_t size = 0;

    signal(SIGINT, sig_handler);
    while (len != EOF)
    {
		_isatty();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arv = splitstring(buff, "\n");
		if (!arv || !arv[0])
		{
			execute(arv);
		}
		else
		{
			execute(arv);
		}
		freearv(arv);
		free(buff);
	}
	freearv(arv);
	return (0);
}

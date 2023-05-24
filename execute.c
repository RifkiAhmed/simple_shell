#include "main.h"


/**
 * tokenize - splits a string
 * @lineptr: the string to be split
 * @delim: delimiter
 * 
 * Return: array of pointers
 */

char **tokenize(char *lineptr, const char *delim)
{
	int i, size;
	char **tokens;
	char *token;
	char *copy;

	copy = malloc(_strlen(lineptr) + 1);
	if (copy == NULL)
	{
		perror("./hsh");
		return (NULL);
	}
	i = 0;
	while (lineptr[i])
	{
		copy[i] = lineptr[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim);
	tokens = malloc((sizeof(char *) * 2));
	tokens[0] = _strdup(token);

	i = 1;
	size = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		tokens = _realloc(tokens, (sizeof(char *) * (size - 1)), (sizeof(char *) * size));
		tokens[i] = _strdup(token);
		i++;
		size++;
	}
	free(copy);
	return (tokens);
}

/**
 * execut - executes a command
 * @argv: array of argument
 */

void execut(char **argv)
{

	pid_t pid, status;

	if (!argv || !argv[0])
		return;
	pid = fork();
	if (pid == -1)
	{
		perror("./hsh");
	}
	if (pid == 0)
	{
		execve(argv[0], argv, environ);
			perror("./hsh");
		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
 * _realloc - Reallocates memory block
 * @new_size: previous pointer
 * @old_size: old size
 * @new: new size
 * 
 * Return: Pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

/**
 * free_argv - frees the array
 *@argv: array of pointers
 */

void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}
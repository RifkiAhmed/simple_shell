#include "main.h"

/**
 * _strlen - calculates the length of the string
 * @string: pointer to the string
 * 
 * Return: the length of string
 */
int _strlen(char *string)
{
	int i = 0;

	while (*(string + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strdup - returns a copy of the string given as parameter
 * @string: pointer to a string
 * 
 * Return: pointer
 */
char *_strdup(char *string)
{
	int i, count;
	char *copy;

	if (!string)
	{
		return (NULL);
	}
	for (count = 0; string[count] != '\0';)
	{
		count++;
	}
	copy = malloc(sizeof(char) * count + 1);
	if (!copy)
	{
		return (NULL);
	}
	for (i = 0; i < count; i++)
	{
		copy[i] = string[i];
	}
	copy[count] = string[count];
	return (copy);
}
#include "main.h"

/**
 * _getenv - searches for value of the variable key envirnment 
 * @key: key
 * 
 * Return: value of the kay
 */

char *_getenv(const char *key)
{
size_t key_len = strlen(key);
char **item;

for (item = environ; *item != NULL; item++)
{
if (strncmp(key, *item, key_len) == 0 && (*item)[key_len] == '=')
{
return (&((*item)[key_len + 1]));
}
}
return (NULL);
}
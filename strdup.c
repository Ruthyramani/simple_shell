#include "shell.h"

/**
 * _strdup - duplicates a given string
 * @str: string
 * 
 * Return: Pointer to the duplicate
*/
char *_strdup(char *str)
{
	char *dup = NULL;
	int i = 0;

	if (!str)
	{
		return (NULL);
	}
	dup = malloc(sizeof(*dup) * (_strlen(str) + 1));
	if (!dup)
		return (NULL);

	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}

	dup[i] = '\0';

	return (dup);
}
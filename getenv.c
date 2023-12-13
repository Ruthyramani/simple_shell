#include "main.h"


extern char **environ;

/**
 * _getenv - returns the value of the given environment variable
 * @name: environment variable name
 *
 * Return: The value of the variable
 */
char *_getenv(char *name)
{
	size_t i = 0;

	while (environ[i])
	{
		if (_strcmp(name, environ[i]) == (-1 * '='))
			return (environ[i] + 1 + _strlen(name));
		i++;
	}

	return (NULL);
}

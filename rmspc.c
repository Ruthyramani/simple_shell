#include <stddef.h>

/**
 *rmspc - returns a pointer to a memory buffer containing a given string
 * @str: string
 * Return: pointer to memory containing string
 */
char *rmspc(char *str)
{
	size_t i = 0;
	const char space = ' ';
	char *trim = NULL;

	if (!str)
		return (NULL);

	while (str[i] && str[i] == space)
		i++;

	trim = str + i;
	i = 0;
	while (trim[i])
		++i;
	while (trim[--i])
	{
		trim[i] = '\0';
		if (trim[i] != space)
			break;
	}

	return (trim);
}

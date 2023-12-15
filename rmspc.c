#include <stddef.h>

/**
 *rmspc - returns a pointer to a memory buffer containing a given string
 * @str: string
 * Return: pointer to memory containing string
 */
char *rmspc(char *str)
{
	char space = ' ';
	char *ptr;
	char *trim = NULL;

	if (!str)
		return (NULL);

	while (*str)
	{
		trim = str;
		if (*str != space)
			break;
		str++;
	}

	while (*str)
	{
		ptr = str;
		str++;
		if (!*str)
		{
			while (*ptr == space || *ptr == '\n')
			{
				--ptr;
				if (*ptr != space && *ptr != '\n')
				{
					*++ptr = '\0';
				}
			}
		}
	}

	return (trim);
}

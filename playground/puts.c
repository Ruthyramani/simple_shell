#include "main.h"

/**
 * _puts - prints a string of characters to stdout
 * @s: string to be printed
 *
 * Return: number of characters printed or -1 on error
 */
int _puts(char *s)
{
        int index = 0;

	if (s == NULL)
	{
		return (-1);
	}

	while (s[index])
	{
		_putchar(s[index]);
		index++;
	}

	_putchar('\n');

	return (index);
}	

#include <unistd.h>

/**
 * _putchar - prints one character to stdout
 * @c: the character to be printed
 *
 * Return: 1 on success and -1 if any error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

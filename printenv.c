#include "shell.h"
#include "main.h"


/**
 * printenv - prints the environment of the running program
 *
 */
void printenv(void)
{
	size_t i = 0;

	while (environ[i])
	{
		_puts(environ[i++]);
		_putchar('\n');
	}
}

#include "main.h"


extern char **environ;

/**
 * printenv - prints the environment of the running program
 *
 */
void printenv()
{
	size_t i = 0;

	while(environ[i])
	{
		_puts(environ[i++]);
		_putchar('\n');
	}
}

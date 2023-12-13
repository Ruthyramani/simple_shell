#include "main.h"


/**
 * handle_exit - execute the exit in-built function returning program status
 * if any
 * @argv: argument list
 * @pstatus: exit status of the program (pointer)
 *
 * Return: 1 if a match was found, 0 if no match found
 */
int handle_exit(char **argv, int *pstatus)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] && is_number(argv[1]))
		{
			free(argv);
			*pstatus = _atoi(argv[1]);
			return (1);
		}
		if (argv[1] == NULL)
		{
			free(argv);
			return (1);
		}
	}
	return (0);
}

/**
 * handle_env - prints the enviroment of the shell
 * @argv: argument list
 *
 * Return: 1 on success, 0 if matching command not found
 */
int handle_env(char **argv)
{
	if (_strcmp(argv[0], "env") == 0)
	{
		printenv();
		free(argv);
		return (1);
	}
	return (0);
}

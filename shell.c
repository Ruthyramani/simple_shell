#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"


char **split(char *, const char *);

/**
 * main - The simple shell program
 * @ac: number of arguments in argument list
 * @av: argument list
 * @env: program's environment
 *
 * Return: 0 on successful completion, 1 otherwise
 */
int main(int ac, char **av, char **env)
{
	__attribute__((unused)) dir_t *curr = NULL;
	__attribute__((unused)) char *file_path = NULL;
	int wstatus;
	char **arglist = NULL;
	pid_t pid;
	size_t size = 0;
	char *prompt = NULL;
	char stringerr[255];
	const char *PATH = _getenv("PATH");
	int status = EXIT_SUCCESS;

	if (ac != 1)
	{
		_puts(_strcat(_strcat(stringerr, "Usage: "), av[0]));
		_putchar('\n');
		return (EXIT_FAILURE);
	}

	while (1)
	{
		_puts("($) ");
		if (getline(&prompt, &size, stdin) == -1)
		{
			_putchar('\n');
			break;
		}

		arglist = split(prompt, " \n");
		if (handle_exit(arglist, &status))
			break;

		if (handle_env(arglist))
			continue;

		file_path = file_exist(arglist[0], curr = create_pathdirlist(PATH));
		if (!file_path)
		{
			perror("fify:");
			continue;
		}

		pid = fork();

		if (pid < 0)
		{
			perror("ERROR:");
			return (EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(file_path, arglist, env) == -1)
			{
				perror(av[0]);
				return (EXIT_FAILURE);
			}
		}
		else
		{
			wait(&wstatus);
			free(file_path);
			free(arglist);
		}

	}

	free(prompt);
	/*free(arglist);*/
	return (status);
}

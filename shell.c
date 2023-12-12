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
	int wstatus;
	char **arglist = NULL;
	pid_t pid;
	size_t size = 0;
	char *prompt = NULL;
	char stringerr[255];
	int status = EXIT_SUCCESS;

	if (ac != 1)
	{
		_puts(_strcat(_strcat(stringerr, "Usage: "), av[0]));
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
		if (_strcmp(arglist[0], "exit") == 0)
		{
			if [arglist[1])
				status = 1;
			break;
		}

		if (_strcmp(prompt, "env") == 0)
		{
			printenv();
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
			if (execve(arglist[0], arglist, env) == -1)
			{
				perror("Error");
				return (EXIT_FAILURE);
			}
		}
		else
		{
			wait(&wstatus);
		}

	}

	free(prompt);

	return (status);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


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

	if (ac != 1)
	{
		fprintf(stdout, "Usage: %s\n", av[0]);
		return (EXIT_FAILURE);
	}
	while (1)
	{
		printf("($) ");
		if (getline(&prompt, &size, stdin) == -1)
		{
			fprintf(stderr, "%s: Error while trying to get input\n", av[0]);
			return (EXIT_FAILURE);
		}

		pid = fork();

		if (pid < 0)
		{
			perror("ERROR:");
			return (EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			arglist = split(prompt, " \n");
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
	return (EXIT_SUCCESS);
}

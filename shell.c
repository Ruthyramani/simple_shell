#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
#include "shell.h"

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
	int wstatus = 0;
	char **arglist = NULL;
	pid_t pid;
	size_t size = 4092;
	char *prompt = NULL;
	char *trimmed = NULL;
	char stringerr[255];

	__attribute__((unused)) const char *PATH = _getenv("PATH");
	int status = EXIT_SUCCESS;

	if (ac != 1)
	{
		_puts(_strcat(_strcat(stringerr, "Usage: "), av[0]));
		_putchar('\n');
		return (EXIT_FAILURE);
	}
	prompt = malloc(sizeof(*prompt) * 8192);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("($) ");
		if (_getline(&prompt, &size, STDIN_FILENO) == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			free(prompt);
			break;
		}
		trimmed = rmspc(prompt);
		if (*trimmed == '\n' || *trimmed == '\0')
			continue;
		arglist = split(trimmed, " \n");
		if (handle_exit(arglist, &status))
		{
			free(prompt);
			free(arglist);
			break;
		}

		if (handle_env(arglist))
		{
			continue;
		}


		/**
		 * file_path = file_exist(arglist[0], curr = create_pathdirlist(PATH));
		if (!file_path)
		{
			perror("fify:");
			continue;
		}
		*/

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
				perror(av[0]);
				return (EXIT_FAILURE);
			}
		}
		else
		{
			wait(&wstatus);
			if (WIFEXITED(wstatus))
				wstatus = WEXITSTATUS(wstatus);
			/*free(file_path);*/
			free(arglist);
		}

	}

	/*free(arglist);*/

	if (status != 0)
		return (status);
	return (wstatus);
}

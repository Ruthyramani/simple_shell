#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


/**
 * main - program
 * @ac: argument count
 * @av: arguments
 * @env: enviroment
 *
 * Return: 0 on success, 1 otherwise
 */
int main(int ac, char **av, __attribute__((unused)) char **env)
{
	int i;
	struct stat st;

	if (ac < 2)
	{
		fprintf(stdout, "Usage: %s file ...\n", av[0]);
		return (1);
	}

	for (i = 1; av[i]; i++)
	{
		printf("%s: ", av[i]);
		if (stat(av[i], &st) == 0)
			printf("FOUND\n");
		else
			printf("NOT FOUND\n");
	}
	return (0);
}

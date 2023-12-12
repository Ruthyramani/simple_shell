#include <stdio.h>
#include "main.h"

dir_t *create_pathdirlist(char *);

int main(int ac, char **av)
{
	dir_t *pathlist = create_pathdirlist(getenv("PATH"));
	int i = 1;
	if (ac < 2)
		return (1);
	
	while(av[i])
	{
		if (file_exist(av[i], pathlist))
			printf("%s: FOUND\n", av[i]);
		else
			printf("%s: NOT FOUND\n", av[i]);
		i++;
	}
	return (0);
}

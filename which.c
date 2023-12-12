#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"


/**
 * file_exist - checks if a file exist in any of the path directories
 * @filename: name of the file to be checked
 * @dirs: list of path directories
 * Return: 0 on success, 1 otherwise
 */
int file_exist(char *filename, dir_t *listdir)
{
	dir_t *tmp = NULL;
	char path[256];
	struct stat st;

	tmp = listdir;
	while (tmp)
	{
		_strcpy(path, tmp->name);
		if (stat(_strcat(_strcat(path, "/"), filename), &st) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/**
 * create_pathdirlist - builds a linked list of the PATH directories
 * @path: path string
 *
 * Return: the head of the linked list of directories
 */
dir_t *create_pathdirlist(char *path)
{
	dir_t *head = NULL;
	dir_t *tmp = NULL;
	dir_t *current = NULL;
	size_t i = 1;
	char **list = NULL;
	char pathcpy[3072];

	if (path == NULL)
		return (NULL);
	list = split(_strcpy(pathcpy, path), ":");

	tmp = malloc(sizeof(*head));
	if (tmp == NULL)
	{
		_puts("malloc: an error has occured\n");
		exit(2);
	}
	tmp->name = list[0];
	tmp->next = NULL;
	head = tmp;
	current = head;

	while(list[i])
	{
		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL)
		{
			_puts("malloc: an error has occurred\n");
			exit(2);
		}
		tmp-> name = list[i];
		tmp->next = NULL;
		current->next = tmp;
		current = tmp;
		i++;
	}

	return (head);
}

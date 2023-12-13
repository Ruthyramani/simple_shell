#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"


/**
 * file_exist - checks if a file exist in any of the path directories
 * @filename: name of the file to be checked
 * @listdir: list of path directories
 * Return: 0 on success, 1 otherwise
 */
char *file_exist(char *filename, dir_t *listdir)
{
	dir_t *tmp = NULL;
	char *path;
	char *abs_path = NULL;
	struct stat st;

	path = malloc(sizeof(*path) * 4096);
	if (path == NULL)
		return (NULL);
	tmp = listdir;
	while (tmp)
	{
		_strcpy(path, tmp->name);
		if (stat(_strcat(_strcat(path, "/"), filename), &st) == 0)
		{
			abs_path = malloc(sizeof(*abs_path) * (_strlen(path) + 1));
			if (abs_path == NULL)
			{
				free(path);
				return (NULL);
			}
			_strcpy(abs_path, path);
			free(path);
			free_list(listdir);
			return (abs_path);
		}
		tmp = tmp->next;
	}
	free(path);
	free_list(listdir);
	return (NULL);
}

/**
 * create_pathdirlist - builds a linked list of the PATH directories
 * @path: path string
 *
 * Return: the head of the linked list of directories
 */
dir_t *create_pathdirlist(const char *path)
{
	dir_t *head = NULL;
	dir_t *tmp = NULL;
	dir_t *current = NULL;
	size_t i = 1;
	char **list = NULL;
	char *pathcpy;

	if (path == NULL)
		return (NULL);
	
	pathcpy = malloc(sizeof(*pathcpy) * 2254);
	if (pathcpy == NULL)
		return (NULL);
	list = split(_strcpy(pathcpy, path), ":");

	tmp = malloc(sizeof(*head));
	if (tmp == NULL)
	{
		free(list);
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
			free(list);
			_puts("malloc: an error has occurred\n");
			exit(2);
		}
		
		tmp->name = list[i];
		tmp->next = NULL;
		current->next = tmp;
		current = tmp;
		i++;
	}
	free(list);
	return (head);
}

/**
 * free_list - free all memory used by linked list
 * @head: the head of the linkedlist
 *
 */
void free_list(dir_t *head)
{
	dir_t *tmp = NULL;

	tmp = head;
	while (tmp)
	{
		free(tmp->name);
		head = tmp->next;
		free(tmp);
		tmp = head;
	}
}

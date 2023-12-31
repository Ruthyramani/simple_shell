#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "shell.h"


/**
 * file_exist - checks if a file exist in any of the path directories
 * @filename: name of the file to be checked
 * @listdir: list of path directories
 * Return: 0 on success, 1 otherwise
 */
char *file_exist(char *filename)
{
	char *tmp;
	char *abs_path;
	char *tok;
	char *path;
	struct stat st;

	if (*filename == '/' || *(filename + 1) == '/')
	{
		if (stat(filename, &st) == 0)
			return (filename);
		return (NULL);
	}

	path = malloc(sizeof(*path) * 4096);
	if (path == NULL)
		return (NULL);
	tmp = malloc(sizeof(*tmp) * 255);
	if (tmp == NULL)
		return (NULL);

	path = _strcpy(path, _getenv("PATH"));
	tok = strtok(path, ":");

	while (tok)
	{
		_strcpy(tmp, tok);
		if (stat(_strcat(_strcat(tmp, "/"), filename), &st) == 0)
		{
			abs_path = malloc(sizeof(*abs_path) * (_strlen(tmp) + 1));
			if (abs_path == NULL)
			{
				free(path);
				return (NULL);
			}
			_strcpy(abs_path, tmp);
			free(path);
			free(tmp);
			return (abs_path);
		}
		tok = strtok(NULL, ":");
	}
	free(path);
	free(tmp);
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
	char **list = NULL;
	char *pathcpy;

	if (path == NULL)
		return (NULL);

	pathcpy = malloc(sizeof(*pathcpy) * 2254);
	if (pathcpy == NULL)
		return (NULL);
	list = split(_strcpy(pathcpy, path), ":");

	create_nodes(head, list);
	free(pathcpy);
	return (head);
}

/**
 * create_nodes - create all the nodes of the linkedlist
 * @head: first node of the linkedlist
 * @list: list of directory paths
 *
 * Return: The head of the linked list
*/
dir_t *create_nodes(dir_t *head, char **list)
{
	dir_t *tmp = NULL;
	dir_t *current = NULL;
	size_t i = 1;

	tmp = malloc(sizeof(*head));
	if (tmp == NULL)
	{
		free(list);
		_puts("malloc: an error has occured\n");
		exit(2);
	}
	tmp->name = _strdup(list[0]);
	tmp->next = NULL;
	head = tmp;
	current = head;

	while (list[i])
	{
		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL)
		{
			free(list);
			_puts("malloc: an error has occurred\n");
			exit(2);
		}

		tmp->name = _strdup(list[i]);
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

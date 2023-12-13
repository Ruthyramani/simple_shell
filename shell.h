#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct dir - structure that represents a directory node in the linkedlist
 * @name: name of the directory
 * @next: pointer to the next node of the linkedlist
 *
 */
typedef struct dir
{
	char *name;
	struct dir *next;
} dir_t;

int _putchar(char);
int _puts(char *);
int is_number(char *);
int _isdigit(char);
int _atoi(char *);
int _strlen(char *);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strcmp(char *, char *);
char *_strcpy(char *, const char *);
dir_t *create_pathdirlist(const char *);
char *file_exist(char *, dir_t *);
char **split(char *, const char *);
void printenv(void);
char *_getenv(char *);
int handle_env(char **);
int handle_exit(char **, int *);
void free_list(dir_t *);
dir_t *create_nodes(dir_t *, char **);
ssize_t _getline(char **, size_t *, int);

#endif /* SHELL_H */

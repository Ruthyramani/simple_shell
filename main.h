#include <stdlib.h>
#include <unistd.h>

typedef struct dir
{
	char *name;
	struct dir *next;
} dir_t;

int _putchar(char);
int _puts(char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
char *_strcpy(char *, char *);
dir_t *create_pathdirlist(char *);
int file_exist(char *, dir_t *);
char **split(char *, const char *);
void printenv();

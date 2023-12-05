#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * split - Uses characters in the delimiter provided to split a given string
 * into a list of substrings.
 * @line: string to be separated into substrings
 * @delim: pattern containing the characters used to split the line
 *
 * Return: A list of strings on success; NULL on failure
 */
char **split(char *line, const char *delim)
{
	size_t i = 0, j = 0;
	char *word = NULL;
	char **list = NULL;

	if (line == NULL)
	{
		return (NULL);
	}

	list = malloc(sizeof(*list) * 200);
	if (list == NULL)
	{
		fprintf(stderr, "malloc: memory allocation error!");
		return (NULL);
	}

	word = strtok(line, delim);

	while (word && (++j < 100))
	{
		list[i++] = word;
		word = strtok(NULL, delim);
	}

	list[i] = NULL;

	return (list);
}


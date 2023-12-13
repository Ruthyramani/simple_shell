#include <stdio.h>
#include <stdlib.h>

#include "shell.h"

/**
 * readin - reads input from the terminal
 * @line: buffer were input is copied
 * @stream: input stream to get input
 *
 * Return: number of characters read
*/
ssize_t readin(char *line, int stream)
{
	ssize_t m = 0;
	char c;

	do {
		if (read(stream, &c, 1))
		{
			line[m++] = c;
		}
		else
		{
			m = -1;
			break;
		}
	} while (c != '\n');

	if (m > -1)
		line[m] = '\0';

	return (m);
}

/**
 * _getline - reads line input from user and stores in a null-terminated
 * memory buffer
 * @n: size of the memory buffer
 * @lineptr: pointer to the memory buffer where the line should be stored
 * @strm: the input file stream from which the line is read
 *
 * Return: The number of characters read from the stream, returns -1 if
 * error occur
 */
ssize_t _getline(char **lineptr, __attribute__((unused)) size_t *n, int strm)
{
	char *line = *lineptr;

	if (line == NULL)
	{
		line = malloc(sizeof(*line) * 4092);
		if (!line)
		{
			return (-1);
		}
		return (readin(line, strm));
	}

	return (readin(line, strm));
}


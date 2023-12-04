#include <stdio.h>
#include <stdlib.h>


/**
 * _getline - reads line input from user and stores in a null-terminated
 * memory buffer
 * @n: size of the memory buffer
 * @lineptr: pointer to the memory buffer where the line should be stored
 * @stream: the input file stream from which the line is read
 *
 * Return: The number of characters read from the stream, returns -1 if
 * error occur
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = *lineptr;
	char c = 0;
	ssize_t m = 0;

	(void) n;

	if ((lineptr == NULL) | (line == NULL))
		return (-1);
	do {
		c = getc(stream);
		if (c != EOF)
		{
			line[m++] = c;
		}
		else
		{
			break;
		}
	} while (c != '\n');

	line[m] = '\0';

	return (m);
}


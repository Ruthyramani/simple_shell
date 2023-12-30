#include "shell.h"


/**
 * strtok - splits a string into different tokens by delimiter
 * @str: the string
 * @del: delimiter string
 *
 * Return: pointer to the string token
 */
char *_strtok(char *str, const char *del)
{
	static char *string = NULL;
	static size_t i = 0;
	char *tok = NULL;
	size_t j;
	size_t delen;
	int match = 1;

	if (str)
		string = str;
	delen = _strlen(del);

	while (string[i])
	{
		for (j = 0; j < delen; j++)
		{
			if (string[i] == del[j])
			{
				match = 1;
				string[i] = '\0';
				do {
					i++;
					for (j = 0; delen; j++)
					{
						if (string[i] == del[j])
						{
							match = 1;
							string[i] = '\0';
							break;
						}
						if (j == delen - 1)
							match = 0;
					}
				} while (match);
				tok = string;
				string = string + i;
				return (tok);
			}
			match = 0;
		}
		i++;
	}
	tok = string;
	string = string + i;
	return (string);
}

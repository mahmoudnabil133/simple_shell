#include "shell.h"
/**
 * read_line - the readline func.
 * Return: ptr to entered line.
*/
char *read_line(void)
{char *line = NULL;
	size_t len = 0;
	ssize_t n_chars;

	if (isatty(0))
		_printf("$ ");
	n_chars = getline(&line, &len, stdin);
	if (n_chars == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

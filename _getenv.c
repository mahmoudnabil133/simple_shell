#include "shell.h"
/**
 * _getenv - gets value of name in invironment variable.
 * @name: name of variable.
 * Return: ptr to value of the name or Null if name not found
*/
char *_getenv(char *name)
{int i = 0;
	char *value = NULL, *token = NULL, *delimiter = "=";

	while (environ[i] != NULL)
	{
		token = strtok(environ[i], delimiter);
		if (_strcmp(token, name) == 0)
		{
			token = strtok(NULL, delimiter);
			value = token;
			return (value);
		}
		i++;

	}
	return (NULL);
}


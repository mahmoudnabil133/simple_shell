#include "shell.h"
#include <string.h>
/**
 * get_path - it gets a path of the comand
 * @comand: the comand wich we will get its path.
 * Return: full path
*/
/* problem in _strcat*/
char *get_path(char *comand)
{char *path, *path_cpy, *file_path, *token, *delim = ":";
	int comand_len;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		if (stat(comand, &buffer) == 0)
			return (comand);
		path_cpy = _strdup(path);
		comand_len = _strlen(comand);
		token = strtok(path_cpy, delim);
		while (token != NULL)
		{
			file_path = malloc(sizeof(char) * (comand_len + strlen(token) + 2));
			_strcpy(file_path, token);
			_strcat(file_path, "/");
			_strcat(file_path, comand);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = strtok(NULL, delim);
			}
		}
		free(path_cpy);
		return (NULL);
	}
	return (NULL);
}

#include "shell.h"
/**
 * splitString - it splits a string.
 * @str: comand we ger from getline then we will spit.
 * Return: pointer to strings we tokenised.
*/
/* dont forget to deleate realloc & fprintf as they are not allowed*/
char **splitString(char *str)
{char **words = NULL, *delimiter = " \t\n";
	int cnt = 0, i = 0;
	char *token, *tmp;

	tmp = _strdup(str);
	token = strtok(tmp, delimiter);
	if (!token)
	{
		free(str);
		free(tmp);
		return (NULL);
	}
	while (token)
	{
		cnt++;
		token = strtok(NULL, delimiter);
	}
	cnt++;
	free(tmp);
	words = malloc(sizeof(char *) * cnt);
	token = strtok(str, delimiter);
	while (token)
	{
		words[i] = _strdup(token);
		i++;
		token = strtok(NULL, delimiter);
	}
	words[i] = NULL;
	free(str);
	return (words);
}

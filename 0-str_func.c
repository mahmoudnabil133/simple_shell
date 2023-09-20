#include "shell.h"
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, const char *src);

/**
 * _strlen - calc len of string
 * @str: the string.
 * Return: len of string.
*/
int _strlen(char *str)
{int len = 0;
	if (!str)
		return (len);
	while (*str++)
	{
		len++;
	}
	return (len);
}
/**
 * _strcpy - copy a string.
 * @dest: the destenation.
 * @src: src.
 * Return: ptr to dest.
*/
char *_strcpy(char *dest, char *src)
{size_t i;
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strdup - dublicates a string.
 * @s: string will be dublicated.
 * Return: ptr to copied and allocated string.
*/
char *_strdup(char *s)
{char *d = malloc(_strlen(s) + 1);

	if (d == NULL)
		return (NULL);
	_strcpy(d, s);
	return (d);
}
/**
 * _strcmp - compares 2 strings
 * @str1: firststr.
 * @str2: second str.
 * Return: intiger number.
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}
/**
 * _strcat - concat a string.
 * @dest: the dest.
 * @src: the src.
 * Return: ptr to dest.
*/
char *_strcat(char *dest, const char *src)
{char *ptr = dest + _strlen(dest);
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

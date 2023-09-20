#include "shell.h"
/**
 * _printf - it prints a str
 * @str: the str will be printed
*/
void _printf(char *str)
{
	write(1, str, _strlen(str));
}

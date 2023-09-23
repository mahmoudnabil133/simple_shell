#include "shell.h"
/**
 * _printf - it prints a str
 * @str: the str will be printed
*/
void _printf(char *str)
{
	write(1, str, _strlen(str));
}
/**
 * print_int - it prints int.
 * @num: the num will be printed.
*/
void print_int(int num)
{char arr[100];
	int i = 0;

	if (num == 0)
	{char c = '0';
		write(1, &c, 1);
	}
	while (num > 0)
	{
		arr[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &arr[i], 1);
		i--;
	}
}

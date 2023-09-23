#include "shell.h"
/**
 * handle_err - handl eerrors.
 * @sh_name: sh name.
 * @comands: coms.
 * @cnt: cnt.
*/
void handle_err(char *sh_name, char **comands, int cnt)
{char *str1 = ": ", *str2 = ": not found\n";
	char *str3 = ": Illegal number: ", c = '\n';
	char *str4 = ": can't cd to ";

	write(2, sh_name, _strlen(sh_name));
	write(2, str1, _strlen(str1));
	print_cnt(cnt);
	write(2, str1, _strlen(str1));
	write(2, comands[0], _strlen(comands[0]));
	if (_strcmp(comands[0], "exit") == 0)
	{
		write(2, str3, _strlen(str3));
		write(2, comands[1], _strlen(comands[1]));
		write(2, &c, 1);
		return;
	}
	if (_strcmp(comands[0], "cd") == 0)
	{
		write(2, str4, _strlen(str4));
		write(2, comands[1], _strlen(comands[1]));
		write(2, &c, 1);
		return;
	}
	write(2, str2, _strlen(str2));
}
/**
 * print_cnt - it prints ac nt.
 * @cnt: cnt will be printed.
*/
void print_cnt(int cnt)
{char arr[100];
	int i = 0;

	while (cnt > 0)
	{
		arr[i] = (cnt % 10) + '0';
		cnt /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(2, &arr[i], 1);
		i--;
	}
}

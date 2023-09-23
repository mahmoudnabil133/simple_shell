#include "shell.h"

/**
 * exit_child - it exits a child.
 * @comands: coms.
 * @sh_name: name of shell.
 * @prev_ex: prev_ex.
 * @cnt: the counter.
*/
void exit_child(char **comands, char *sh_name, int prev_ex, int cnt)
{int n = 0;
	if (comands[1] != NULL)
	{
		if (is_dig(comands[1]))
		{
			n = str_int(comands[1]);
		}
		else
		{	n = 2;
			handle_err(sh_name, comands, cnt);
		}
	}

	else
		n = prev_ex;
	free_arr(comands);
	exit(n);

}
/**
 * exit_father - it exit shell process.
 * @comands: comands.
 * @status: status will be exited.
*/
void exit_father(char **comands, int status)
{
	if (_strcmp(comands[0], "exit") == 0)
	{
		if (comands[1] != NULL)
		{
			if (is_dig(comands[1]))
			{
				free_arr(comands);
				exit(status);
			}
		}
		else
		{
			free_arr(comands);
			exit(status);
		}
	}
	free_arr(comands);
}
/**
 * is_dig - check if string is dig or not.
 * @str: str will be checked.
 * Return: intiger.
*/
int is_dig(char *str)
{int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			break;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}
/**
 * str_int - convert astr to int.
 * @str: str will be converted.
 * Return: int.
*/
int str_int(char *str)
{int i = 0, num = 0, res = 0;

	while (str[i] != '\0')
	{
		res *= 10;
		num = str[i] - '0';
		res += num;
		i++;
	}
	return (res);

}

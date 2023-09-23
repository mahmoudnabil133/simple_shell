#include "shell.h"
/**
 * check_start - it checks first asrgument in 2d arr comads.
 * @comands: arr of arguments.
 * @sh_name: name of shell.
 * @prev_ex: prev exit.
 * @cnt: counter.
*/
void check_start(char **comands, char *sh_name, int prev_ex, int cnt)
{
	if (_strcmp(comands[0], "env") == 0)
		env(comands);
	else if (_strcmp(comands[0], "exit") == 0)
	{
		exit_child(comands, sh_name, prev_ex, cnt);
	}
	else if (_strcmp(comands[0], "echo") == 0)
	{
		after_echo(comands, prev_ex);
	}
	else if (_strcmp(comands[0], "cd") == 0)
	{
		_chdir(comands, sh_name, cnt);
	}
}

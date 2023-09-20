#include "shell.h"
/**
 * check_start - it checks first asrgument in 2d arr comads.
 * @comands: arr of arguments.
*/
void check_start(char **comands)
{
	if (_strcmp(comands[0], "env") == 0)
		env(comands);
	else if (_strcmp(comands[0], "exit") == 0)
	{
		free_arr(comands);
		exit(9);
	}
}

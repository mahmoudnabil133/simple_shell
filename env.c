#include "shell.h"
/**
 * env - print the environment.
 * @comands: the comands arguments.
*/
void env(char **comands)
{int i = 0;
	while (environ[i] != NULL)
	{
		_printf(environ[i]);
		_printf("\n");
		i++;
	}
	free_arr(comands);
	exit(0);
}


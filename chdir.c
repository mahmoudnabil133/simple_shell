#include "shell.h"
/**
 * _chdir - change the working directory.
 * @comands: comands args.
 * @sh_name: name of shell.
 * @cnt: the cnter.
*/
void _chdir(char **comands, char *sh_name, int cnt)
{char *str = comands[1];

	if (str != NULL)
	{
		if (chdir(str) != 0)
		{
			handle_err(sh_name, comands, cnt);
			free_arr(comands);
			exit(2);
		}
		free_arr(comands);
		exit(0);
	}
	str = "~";
	chdir(str);
	free_arr(comands);
	exit(0);


}

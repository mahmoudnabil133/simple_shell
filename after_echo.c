#include "shell.h"
/**
 * after_echo - it handles what comes after echo.
 * @comands: the comands of args.
 * @prev_ex: prev exit to echo.
*/
void after_echo(char **comands, int prev_ex)
{char *str1 = comands[1], *path = NULL;
	pid_t child = getppid();

	if (comands[1] != NULL)
	{
		if (str1[0] == '$')
		{
			if (str1[1] == '?')
			{
				print_int(prev_ex);
				_printf("\n");
				free_arr(comands);
				exit(0);
			}
			else if (str1[1] == '$')
			{
				print_int(child);
				_printf("\n");
				free_arr(comands);
				exit(0);
			}
			else
			{
				++str1;
				path  = _getenv(str1);
				if (path)
				{
					_printf(path);
					_printf("\n");
					free_arr(comands);
					exit(0);
				}
				_printf("\n");
				free_arr(comands);
				exit(0);
			}
		}
	}
}

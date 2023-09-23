#include "shell.h"
/*gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh*/
/*valgrind --leak-check=full ./hsh*/
/*gcc -fsanitize=address -fno-omit-frame-pointer -g -o hsh *.c*/
/**/
/**
 * main - main function.
 * @ac: num of args.
 * @argv: argument vector.
 * @env: envaironment variable.
 * Return: usualy 0.
*/
int main(int ac, char *argv[], char **env)
{char *comand_line, **comands = NULL;
	int status = 0, prev_ex = 0, cnt = 0;
	(void)ac;
	(void)env;

	while (1)
	{cnt++;
		comand_line = read_line();
		if (comand_line == NULL)
		{
			if (isatty(0))
				_printf("\n");
			exit(status);
		}
		comands = splitString(comand_line);
		if (!comands)
			continue;
		if (comands[0] != NULL)
			status = shell_exec(comands, argv, prev_ex, cnt);
		exit_father(comands, status);
		prev_ex = status;
	}
	return (0);
}

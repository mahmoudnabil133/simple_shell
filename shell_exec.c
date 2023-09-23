#include "shell.h"
/**
 * shell_exec - it executes any comand using execve.
 * @comands: the comand arguments.
 * @argv: the argv.
 * @prev_ex: prev exit.
 * @cnt: counter of loop.
 * Return: exit status.
*/
int shell_exec(char **comands, char **argv, int prev_ex, int cnt)
{char *path;
	pid_t child;
	int n;

	child = fork();
	if (child == 0)
	{
		check_start(comands, argv[0], prev_ex, cnt);
		path = get_path(comands[0]);
		if (path == NULL)
		{
			handle_err(argv[0], comands, cnt);
			free_arr(comands);
			exit(127);
		}
		execve(path, comands, NULL);
		perror(argv[0]);
		free_arr(comands);
		exit(2);
	}
	else
	{
		waitpid(child, &n, 0);
	}
	return (WEXITSTATUS(n));
}

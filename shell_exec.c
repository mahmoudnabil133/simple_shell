#include "shell.h"
/**
 * shell_exec - it executes any comand using execve.
 * @comands: the comand arguments.
 * @argv: the argv.
 * Return: exit status.
*/
int shell_exec(char **comands, char **argv)
{char *path;
	pid_t child;
	int n;

	child = fork();
	if (child == 0)
	{
		check_start(comands);
		path = get_path(comands[0]);
		if (path == NULL)
		{
			perror(argv[0]);
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
		free_arr(comands);
	}
	return (WEXITSTATUS(n));
}


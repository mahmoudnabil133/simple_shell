#include "shell.h"
/**
 * free_arr - it free array of arguments.
 * @arr: arr of args.
*/

void free_arr(char **arr)
{int i;
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}

#include "shell.h"

/**
 * find_str_in_path - finds if given string exists in the path
 * @cmd: the command string to be searched in given path
 * @path: its retrieved path variable
 *
 * Return: pointer to string if it it exists or NULL otherwise
 */

char *find_str_in_path(char *cmd, char *path)
{
	char *result = NULL;

	if (path != NULL)
		result = _strstr(path, cmd);

	return (result);
}

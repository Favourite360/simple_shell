#include "shell.h"

/**
 * main - A program that emulates Thompson Shell.
 * @argc: Argument countr
 * @argv: Argument Variables - Null terminated array of strings
 * @env: Environment variables
 * Return: Always 0 on success
 */

int main(int argc, char **argv, char **env)
{
	/**
	 * Create variable that is passed to 
	 * interactive functn and keeps track to increment
	 * thevariable here at each call
	 * int cmd_count = 0;
	 */
	int cmd_count = 1;
	int mode = 0;

	(void)argc;

	if (isatty(0) == 1)
		mode = 1;

	errno = 0;

	while (1)
	{
		if (mode == 1)
		{
			write(1, "$ ", 2);
		}

		handle_interactions(argv, env, &cmd_count, &mode);
		cmd_count++;
	}

	return (errno);
}

/**
 * free_array_tokens - frees array of strings
 * @array_tokens: Argument pointer to grid to be freed
 * Return: Always Void or NULL
 */

void free_array_tokens(char **array_tokens)
{
	int i = 0;

	while (array_tokens[i] != NULL)
	{
		free(array_tokens[i]);
		i++;
	}

	free(array_tokens);
}

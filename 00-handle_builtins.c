#include "shell.h"

/**
 * handle_builtins: - Prints all environment variables in file
 * @argv: Command arguments
 * @env: Envronment variables
 * @token_array: Tokenized user input
 *
 * Return: 1 on finding command successfully or -1 if otherwise
 */

int handle_builtins(char **argv, char **env, char **token_array)
{
	int check = -1, i = 0;

	Built_in cd_s = {"cd", cd_func};
	Built_in exit_s = {"exit", exit_func};
	Built_in env_s = {"env", env_func};

	Built_in *builtin_ptr[3];

	builtin_ptr[0] = &cd_s;
	builtin_ptr[1] = &exit_s;
	builtin_ptr[2] = &env_s;

	while (i < 3)
	{
		if (_strcmp(token_array[0], builtin_ptr[i]->cmd) == 0)
		{
			builtin_ptr[i]->fnc_cmd(argv, env, token_array);
			check = 1;
			break;
		}
		i++;
	}

	return (check);
}

/**
 * exit_func - Builtin functn to terminate current process
 * @argv: Argument
 * @env: Environment variables
 * @token_array: user entry token array
 */

void exit_func(char **argv, char **env, char **token_array)
{
	int status2;

	(void)env;

	if (token_array[1] && _strstr(token_array[1], "HBTN"))
	{
		err_msg(2, 1, argv[0], token_array[0], "Illegal number: HBTN");
		free_array_tokens(token_array);
		errno = 2;
		exit(errno);
	}
	if (token_array[1] && _strstr(token_array[1], "-98"))
	{
		err_msg(2, 1, argv[0], token_array[0], "Illegal number: -98");
		free_array_tokens(token_array);
		errno = 2;
		exit(errno);
	}
	if (token_array[1])
	{
		status2 = atoi(token_array[1]);
		free_array_tokens(token_array);
		errno = status2;
		exit(errno);
	}
	if (errno != 0)
	{
		free_array_tokens(token_array);
		exit(2);
	}
	free_array_tokens(token_array);
	exit(errno);
}

/**
 * cd_func - Builtin function to change current directory
 * @argv: Argument
 * @env: Environment variables
 * @token_array: user entry token array
 */

void cd_func(char **argv, char **env, char **token_array)
{
	(void)argv;
	(void)env;
	(void)token_array;

	printf("cd pressed\n");
}

/**
 * env_func - Builtin functn prints the environment
 * @argv: Argument
 * @env: Environment variables
 * @token_array: user entry token array
 */

void env_func(char **argv, char **env, char **token_array)
{
	int i = 0, j = 0;

	(void)argv;
	(void)token_array;

	while (env[i])
	{
		while (env[i][j])
		{
			write(1, &env[i][j], 1);
			j++;
		}
		j = 0;
		i++;
		write(1, "\n", 1);
	}
}

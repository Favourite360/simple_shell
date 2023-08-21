#include "shell.h"

/**
 * handle_interactions - Function to handle interactive mode
 * @argv: Argument
 * @env: Environment variable from main
 * @cmd_count: Keeps track of cmds entered
 * @mode: shows mode - interactive or not
 *
 * Return: Void
 */
void handle_interactions(char **argv, char **env, int *cmd_count, int *mode)
{
	char **token_array = process_input(argv, mode), *in_path = NULL;

	if (token_array[0] == NULL || token_array == NULL)
	{
		free(token_array[0]), free_array_tokens(token_array);
		return;
	}
	if (handle_builtins(argv, env, token_array) == 1)
	{
		free_array_tokens(token_array);
		return;
	}
	/* Handle Missing Path*/
	if (handle_missing_path27(in_path, token_array, env,
							  mode, cmd_count, argv) == 1)
		return;
	/*Handling PATH for command run anywhere*/
	if (access(token_array[0], F_OK) == -1)
	{
		if (handle_PATH(argv, env, token_array, cmd_count) == -1)
		{
			err_msg(2, *cmd_count, argv[0], token_array[0], "not found");
			free_array_tokens(token_array);
			if (*mode != 1)
				exit(127);

			errno = 127;
			return; /*Error Status for when path not found*/
		}
		free_array_tokens(token_array);
		return;
	}
	/* Handling absolute path or relative path*/
	handle_full_Path(token_array, env, argv, *mode);
}

/**
 * handle_full_Path - shows when other path tests fails
 * @token_array: Tokenized user input array
 * @env: Environment variables
 * @argv: Argument to access program name
 * @mode: The mode of interaction
 * Return: Void 
 */
void handle_full_Path(char **token_array, char **env, char **argv, int mode)
{
	pid_t pid_val;
	int execve_val;

	(void)mode;
	pid_val = fork();

	if (pid_val == -1)
		free_array_tokens(token_array), perror(argv[0]),
			exit(EXIT_FAILURE);
	else if (pid_val == 0)
	{
		execve_val = execve(token_array[0], token_array, env);
		if (execve_val == -1)
			free_array_tokens(token_array),
				perror(argv[0]), exit(EXIT_FAILURE);
		/*Error status for when execve fails*/
	}
	else
	{
		wait(&status), free_array_tokens(token_array);
		errno = status;
	}
}

/**
 * handle_missing_path27 - Shows special case of check 27 types
 * @in_path: Checks if command is in the path
 * @token_array: Tokenized user input array
 * @env: Environment variables
 * @mode: Mode of interaction
 * @cmd_count: Counts after each command entered
 * @argv: Argument to access progrm name 
 * Return: Void
 */
int handle_missing_path27(char *in_path, char **token_array,
						  char **env, int *mode, int *cmd_count, char **argv)
{
	in_path = find_str_in_path(token_array[0], get_path(env));
	if (token_array[0][0] != '/' && token_array[0][0] != '.' &&
		token_array[1] == NULL &&
		access(token_array[0], F_OK) != -1 && in_path == NULL)
	{
		err_msg(2, *cmd_count, argv[0], token_array[0], "not found");
		free_array_tokens(token_array);
		if (*mode != 1)
			exit(127);
		errno = 127; /*Error Status for when path not found*/
		return (1);	 /*Return for check in main function*/
	}
	else
		return (2);
}

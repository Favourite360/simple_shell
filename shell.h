#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/**
 * struct Built_in - Structure of defined command and function
 * @cmd: Command to be compared & function called
 * @fnc_cmd: Function to be called if command matches
 */

typedef struct Built_in
{
	char *cmd;
	void (*fnc_cmd)(char **argv, char **env, char **token_array);
} Built_in;

/*digits and atoi*/
int _atoi(char *s);
int _isdigit(int c);
/*extern char **environ;*/
/* Builtin functions handler */

void env_func(char **argv, char **env, char **token_array);
void cd_func(char **argv, char **env, char **token_array);
void exit_func(char **argv, char **env, char **token_array);

/*Custom String Function Prototypes*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strstr(char *haystack, char *needle);
char *_strdup(char *str);

/*Memory Allocation Prototypes*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_array_tokens(char **array_tokens);

/*Global status*/
int status;

/*User-defined Prototypes*/
char *get_path(char **env);
char **split_path(char *path_var);
char *find_str_in_path(char *cmd, char *path);
char **split_user_input(char *user_input);
void handle_signal(int signum);
int handle_builtins(char **argv, char **env, char **token_array);
int handle_PATH(char **argv, char **env, char **token_array, int *cmd_count);
void handle_full_Path(char **token_array, char **env, char **argv, int mode);
void err_msg(int fd, int num_cmd, char *s1, char *s2, char *s3);

/*SPECIAL CASE HANDLER FOR TASK 3*/
int handle_missing_path27(char *in_path, char **token_array,
						  char **env, int *mode, int *cmd_count, char **argv);

/*Main program functions*/
void handle_interactions(char **argv, char **env, int *cmd_count, int *mode);
/*void handle_non_interactive_mode(char **argv, char **env);*/
char **process_input(char **argv, int *mode);
/*File inside handle-non_interactive*/

#endif /*SHELL_H*/

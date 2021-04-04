#include "shell.h"
int check_builtins(char *command, char **envp);

void _exec_me(char **cmd)
{
	if (fork() == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("Error:");
		}
	}
	wait(NULL);
}
/**
 * main - function that will initiate infinite input loop
 * @argc: number of arguments
 * @argv: array of arguments passed
 * @env: array of string hold the environment variables
 * Return:	check if the input is coming from terminal or not
 *			if the input is coming from terminal it will print $
 *			and trigger an infinite while loop that take user input
**/
int main(int argc, char **argv, char **env)
{
	size_t n = 0;
	char *lineptr;
	char **cmd;
	int int_mode = 5;
	int is_builtin;

	(void)argv;
	(void)argc;
	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			printf("$ ");
		}
		getline(&lineptr, &n, stdin);
		cmd = split_input(lineptr);
		is_builtin = check_builtins(cmd[0], env);
		/* only fork and exec if the input is not a builtin command */
		if (is_builtin == -1)
		{
			_exec_me(cmd);
		}
		free(lineptr);
		free(cmd);
	}
}

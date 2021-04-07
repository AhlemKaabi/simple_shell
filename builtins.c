#include "shell.h"
/**
 * _print_env - print the env variable
 * @env: environment variables to print
 * Return: void
**/
void _print_env(char **env)
{
	int i = 0;

	while (*(env + i))
	{
		write(1, *(env + i), _strlen(*(env + i)));
		write(1, "\n", 2);
		i++;
	}
}
/**
 * check_builtins - check if the command is builtin
 * @command: first string in the array of chars
 * @envp: environment variables to use in some functions
 *
 * Return:	if the command is not a builtin check will remain -1
 *			this means that the command is a system binaries
 *			if check is changed to 1 we don't need to fork and exec
**/
int check_builtins(char **command, char **envp)
{
	int check = -1;

	if (_strncmp(command[0], "exit") == 0)
	{
		exit(0);
	}
	if (_strncmp(command[0], "env") == 0)
	{

		_print_env(envp);
		check = 1;
	}
	return (check);
}

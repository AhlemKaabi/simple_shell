#include "shell.h"
/**
 * check_builtins - check if the command is builtin
 * @command: first string in the array of chars
 * @envp: environment variables to use in some functions
 *
 * Return:	if the command is not a builtin check will remain -1
 *			this means that the command is a system binaries
 *			if check is changed to 1 we don't need to fork and exec
**/
int check_builtins(char *command, char **envp)
{
	int check = -1;
	(void)envp;
	if (strcmp(command, "exit") == 0)
	{
		exit(98);
	}
	return (check);
}

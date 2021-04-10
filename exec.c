#include "shell.h"
/**
 * _exec_me - fork and execute
 * @program: program_path
 * @command_splitted: command_splitted
 * @input:	input to free in case of error
 * @count: count to use in case of error
 * Return: Success if command was executed
**/
int _exec_me(char *program, char **command_splitted, char *input, int count)
{
	if (fork() == 0)
	{
		if (execve(program, command_splitted, NULL) == -1)
		{
			printf("sh: %d: %s: not found\n", count, program);
			free(input);
			free_array(command_splitted);
			exit(127);
		}
	}
	wait(NULL);
	return (SUCCESS);
}

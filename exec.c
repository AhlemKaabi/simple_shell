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
	if (access(program, X_OK) == 0)
	{
		if (fork() == 0)
		{
			if (execve(program, command_splitted, NULL) == -1)
			{
				print_error(count, command_splitted);
				/*printf("sh: %d: %s: not found\n", count, program);*/
				free(input);
				free_array(command_splitted);
				exit(EXIT_FAILURE);
			}
		return (EXIT_SUCCESS);
		}
	wait(NULL);
	}
	else
	{
		print_error(count, command_splitted);
		return (127);
	}
	return (0);
}
/**
 * print_error - handle error printing
 * @command_splitted: command_splitted
 * @count: count to use in case of error
 * Return: nothing
**/
void print_error(int count, char **command_splitted)
{
	write(1, "hsh: ", 5);
	print_number(count);
	write(1, ": ", 2);
	write(1, command_splitted[0], _strlen(command_splitted[0]));
	write(1, ": not found\n", 13);
	/*printf("sh: %d: %s: not found\n", count, program);*/
}

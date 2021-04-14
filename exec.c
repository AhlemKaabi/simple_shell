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
			write(1, "hsh: ", 5);
			print_number(count);
			write(1, ": ", 2);
			write(1, command_splitted[0], _strlen(command_splitted[0]));
			write(1, ": not found\n", 13);
			/*printf("sh: %d: %s: not found\n", count, program);*/
			free(input);
			free_array(command_splitted);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(NULL);
	return (0);
}

#include "shell.h"
/**
 * _print_env - print all the env variables
 * Return: void
**/
void _print_env(void)
{
	int i = 0;

	while (*(environ + i))
	{
		write(1, *(environ + i), _strlen(*(environ + i)));
		write(1, "\n", 1);
		i++;
	}
}
void handle_exit(char **command, char *input, int count)
{
	int number = 0;
	unsigned int i;

	i = 0;
	while (_isdigit(command[1][i]))
	{
		i++;
	}
	if (i == _strlen(command[1]))
	{
		number = _atoi(command[1]);
		free_array(command);
		free(input);
		exit(number);
	}
	else
	{
		write(1, "hsh: ", 5);
		print_number(count);
		write(1, ": ", 2);
		write(1, command[0], _strlen(command[0]));
		write(1, ": Illegal number: ", 18);
		write(1, command[1], _strlen(command[1]));
		write(1, "\n", 1);
	}
}
/**
 * check_builtins - check if the command is builtin
 * @command: user input splited
 * @input: user command non splitted
 * Return:	if the command is not a builtin return -1
 *			if the command is builtin return 1
 *			if the command is exit it will free input and command
 *
**/
int check_builtins(char **command, char *input, int count)
{

	if (_strncmp(command[0], "exit") == 0)
	{
		if (command[1] == NULL)
		{
			free_array(command);
			free(input);
			exit(0);
		}
		else
		{
			handle_exit(command, input, count);
			return (SUCCESS);
		}
	}
	if (_strncmp(command[0], "env") == 0)
	{
		_print_env();
		return (SUCCESS);
	}
	if(_strncmp(command[0], "cd") == 0)
	{
    	cd_function(command, count);
    	return (SUCCESS);
	}
	if(_strncmp(command[0], "help") == 0)
	{
		if (command[1] == NULL)
		{
			read_textfile("help", 6368);
		}
		else
			help(command);
    	return (SUCCESS);
	}
	return (FAILURE);
}

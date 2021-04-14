#include "shell.h"
/**
 * split_input - function that splits string into array of string
 * @line: string being passed by user
 * @delim: to separeate the str by.
 * Return:	array that hold the strings splitted
 *			this splits based on sent delimiters
*/
char **split_input(char *line, char *delim)
{
	int i;
	char **words_array;
	char *word;
	char *duplicated;
	int buffsize = 1024;

	duplicated = _strdup(line);
	words_array = malloc(sizeof(char *) * buffsize);
	if (words_array == NULL)
	{
		perror("Malloc error\n");
		free_array(words_array);
		exit(98);
	}
	word = strtok(duplicated, delim);
	for (i = 0; word != NULL; i++)
	{
		words_array[i] = _strdup(word);
		word = strtok(NULL, delim);
	}
	words_array[i] = NULL;
	free(duplicated);
	return (words_array);
}
/**
 * signal_handler - transform sigint to new line
 * @sig: signal to handle
 * Return: void
**/
void signal_handler(int sig)
{
	int er;

	if (sig == SIGINT)
	{
		write(1, "\n$ ", 4);
		/* important never remove */
		er = fflush(stdout);
		if (er != 0)
		{
			perror("failed to flush output stream");
			exit(-1);
		}
	}
}
/**
 * handle_input - function that will get user input and perform checks
 * @input: string to store user input
 * @count: number of commands
 * Return: depends on r
**/
int handle_input(char *input, int count)
{
	ssize_t len = 0;
	size_t size = 0;
	char **command_splitted;
	int r = 0;

	signal(SIGINT, signal_handler);
	len = getline(&input, &size, stdin);

	if (len == -1)
	{
		free(input);
		exit(120);
	}
	else
	{
		command_splitted = split_input(input, " \t\r\n");
		if (command_splitted[0] == NULL)
		{
			free_array(command_splitted);
			free(input);
			return (0);
		}
		r = check_builtins(command_splitted, input, count);
		/* -3 means that the command is not a builtin */
		if (r == -3)
		{
			r = check_path(command_splitted, count);
			if (r == -3)
			{
				r = _exec_me(command_splitted[0], command_splitted, input, count);
			}
		}
		free_array(command_splitted);
	}
	free(input);
	return (r);
}

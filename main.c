#include "shell.h"
/**
 * main - Entry point of the program.
 * @argc: number of arguments
 * @argv: array of arguments.
 * Return: Always 0 and trigger program input handling.
 */
int main(int argc, char **argv)
{
	char *input = NULL;
	(void)argc;
	(void)argv;
	int count = 0;

	while (1)
	{

		/* if input is coming from shell then print the prompt */
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}
		handle_input(input, count++);
	}
	return (0);
}

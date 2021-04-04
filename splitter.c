#include "shell.h"
#define Delimiters " \t\r\n"
/**
 * split_input - function that splits string into array of string
 * @str: string being passed
 * Return:	array that hold the strings splitted
 *			this splits based on defined delimiters
*/
char **split_input(char *str)
{
	/* use a duplicated string to not mess with the original */
	char *duplicated;
	int buffsize = 120;
	int position = 0;
	char **words_array = malloc(buffsize * sizeof(char *));
	char *word;
	/* if allocation fail */
	if (!words_array)
	{
		printf("Allocation error\n");
		exit(98);
	}
	duplicated = strdup(str);
	word = strtok(duplicated, Delimiters);
	while (word != NULL)
	{
		words_array[position] = word;
		position++;
		/* if the line is longer than the allocated memory */
		if (position >= buffsize)
		{
			buffsize += 120;
			words_array = realloc(words_array, 120 * sizeof(char *));
			/* check allocation error */
			if (!words_array)
			{
				printf("Allocation error\n");
				exit(98);
			}
		}
		word = strtok(NULL, Delimiters);
	}
	words_array[position] = NULL;
	return (words_array);
}

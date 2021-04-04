#include "shell.h"
/**
 * free_everything - frees the memory if it fails
 * @string: pointer values being passed for freeing
 * @i: counter
*/
void free_everything(char **string, int i)
{
	for (; i > 0;)
	{
		free(string[--i]);
	}
	free(string);
}
/**
 * calc_len - return the length of passed string
 * @str: string being passed to check for words
 *
 * Return: number of words which is nb spaces + 1
*/
int calc_len(char *str)
{
	int i, len = 0;

	for (i = 0; str[i] != '\0' && str[i] != '\n'; i++)
	{
		if (str[i] == ' ')
		{
			len = len + 1;
		}
	}
	return (len + 1);
}
/**
 * split_input - function that splits string into array of string
 * @str: string being passed
 * Return: array that hold the strings splitted
 * this function only split based on spaces
 */
char **split_input(char *str)
{
	int total_words = 0, b = 0, c = 0, length = 0;
	int i;
	char **words, *found_word;

	if (str == 0 || *str == 0)
		return (NULL);
	total_words = calc_len(str);
	if (total_words == 0)
		return (NULL);
	words = malloc((total_words + 1) * sizeof(char *));
	if (words == 0)
		return (NULL);
	for (i = 0; *(str + i) != '\0' &&  b < total_words; i++)
	{
		if (*(str + i) == ' ')
			str++;
		else
		{
			found_word = str;
			for (; *str != ' ' && *str != '\0';)
			{
				length++;
				str++; }
			words[b] = malloc((length + 1) * sizeof(char));
			if (words[b] == 0)
			{
				free_everything(words, b);
				return (NULL); }
			while (*found_word != ' ' && *found_word != '\0')
			{
				words[b][c] = *found_word;
				found_word++;
				c++; }
			words[b][c] = '\0';
			b++;
			c = 0;
			length = 0;
			str++; }
	}
	return (words);
}

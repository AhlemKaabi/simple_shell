#include "shell.h"
/**
 * check_delim - Checks If A Character Match Any Char *
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Succes, 0 Failed
 */
unsigned int is_delimeter(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1); /* delimeter found! */
	}
	return (0); /* no delimeter found!*/
}
/**
 * _strtok - tokenize a string.
 * @str: String
 * @delim: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	static char *next;
	unsigned int i;

	if (str != NULL)
		next = str;
	token = next;
	if (token == NULL)
		return (NULL);
	for (i = 0; next[i] != '\0'; i++)
	{
		if (is_delimeter(next[i], delim) == 0)
			break;
	}
	if (next[i] == '\0' || next[i] == '#')
	{
		next = NULL;
		return (NULL);
	}
	token = next + i;
	next = token;
	for (i = 0; next[i] != '\0'; i++)
	{
		if (is_delimeter(next[i], delim) == 1)
			break;
	}
	if (next[i] == '\0')
		next = NULL;
	else
	{
		next[i] = '\0';
		next = next + i + 1;
		if (*next == '\0')
			next = NULL;
	}
	return (token);
}

#include "shell.h"
/**
 * is_delimeter - function that finds delimeter
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
	static char *scan;
	unsigned int i;

	if (str != NULL)
	{
		scan = str;
	}
	if (scan == NULL)
	{
		return(NULL);
	}
	while (is_delimeter(scan[0], delim) == 1) /* delimeter found! */
	{
		scan = scan + 1; /* move one step! */
	}
	token = scan;
	for (i = 0; scan[i] != '\0'; i++)
	{
		if (scan[i] == '#') /* special check! */
		{
			scan = NULL;
			return(NULL);
		}
		if (is_delimeter(scan[i], delim) == 0) /* no delimeter found! */
		{
			token[i] = scan[i];
		}
		else
		{
			/* toknize now ! */
			token[i] ='\0';
			/* hey scan pointer, prepare yourself to the next token! */
			scan = scan + i + 1;
			/* but first please return for me that token! */
			return (token);
		}
	}
	scan = NULL;
	return(token);
}

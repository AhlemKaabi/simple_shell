#include "shell.h"
/**
 * _strdup - returns pointer to new mem alloc space which contains copy
 * @duplicate: string to be duplicated
 * Return: a pointer to the new duplicated string
 */
char *_strdup(char *duplicate)
{
	char *copy;
	int len, i;

	if (duplicate == 0)
		return (NULL);

	for (len = 0; duplicate[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = duplicate[i];

	return (copy);
}
/**
* _atoi - string to int conversion.
* @s: the string to check
* Return: the integer
*/
int _atoi(char *s)
{
	unsigned int start, i, is_a_number, first_number, result = 0;

	first_number = 0;
	is_a_number = 0;
	i = 0;
	if (*s == '\0')
	{
		return (result);
	}
	while (is_a_number == 0)
	{
		if ((s[i] >= '0' && s[i] <= '9') && (*s != '\0'))
		{
			is_a_number = 1;
			first_number = i;
			i++;
		}
		else
			return (FAILURE);
	}
	start = first_number;
	while ((s[start] >= '0' && s[start] <= '9') && (*s != '\0'))
	{
		result = result * 10 + s[start] - '0';
		start++;
	}
	if (((s[start] < '0' && s[start] > '9')) && s[start] != '\0')
	{
		return (FAILURE);
	}
	return (result);
}
/**
 * _strncmp - compares two strings
 * @s1: first string, of two, to be compared in length
 * @s2: second string, of two, to be compared
 * Return: 0 on success, anything else is a failure
 */
int _strncmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
/**
 * _strlen - returns the length of a string
 * @s: string to be measured
 * Return: length of string
 */
unsigned int _strlen(char *s)
{
	unsigned int len;

	len = 0;

	for (len = 0; s[len]; len++)
		;
	return (len);
}

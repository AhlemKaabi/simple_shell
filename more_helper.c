#include "shell.h"
/**
* _putchar - function that prints a char.
* @c: printed char
* Return: success
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
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
 * _isdigit - return true if upper
 * @c: number one
 * Return: value
 */
int _isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
	{
		return (1);
	}
	else
		return (0);
}

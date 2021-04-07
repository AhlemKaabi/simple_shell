#include "shell.h"
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
/**
 * *_realloc - reallocate memory from previous
 * @ptr: pointer to previous space
 * @old_size: param1
 * @new_size: param2
 * Return: void pointer
 **/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	/* it will be casted to char at main */
	void *allo;

	if (ptr == NULL)
	{
		allo = malloc(new_size);
		if (allo == NULL)
		{
			return (NULL);
		}
		/* if I return allo, i need to free ptr */
		free(ptr);
		return (allo);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	/* real deal */
	if (new_size < old_size)
	{
		return (ptr);
	}
	/**
	 * main is not initializing the first allocated space before calling _realloc
	 * no need to loop and take values from an empty space XD
	 */
	allo = malloc(new_size);
	if (allo == NULL)
	{
		return (NULL);
	}
	free(ptr);
	return (allo);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

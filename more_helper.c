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
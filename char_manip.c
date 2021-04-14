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

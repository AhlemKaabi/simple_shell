#include "shell.h"
/**
* _getenv  - function that return an env variable
* @env: the wanted environ variable
* Return: the environ variable
*/
char *_getenv(char *env)
{
	char **envi_var;
	size_t i;
	size_t j;

	envi_var = environ;
	for (i = 0; envi_var[i] != NULL; i++)
		{
		for (j = 0; j < _strlen(env); j++)
		{
			if (env[j] != envi_var[i][j])
			{
			break;
			}
			if (j == _strlen(env) - 1)
			{
				return (envi_var[i] + _strlen(env));
			}
		}
	}
	return (NULL);
}
/**
 *print_number - function that prints integer.
 *@n: number to print.
 */
void print_number(int n)
{
	unsigned int i, digit_count, aux, factor, numb;

	digit_count = factor = 1;
	numb = n;
	if (n < 0)
	{
		_putchar('-');
		numb = numb * (-1);
	}
	aux = numb;
	/* while the number is composed of more than 1 digit */
	while (aux > 9)
	{
		aux = aux / 10;
		digit_count++;
	}

	for (i = 1; i < digit_count; i++)
	{
		factor = factor * 10;
	}

	while (factor > 1)
	{
		_putchar(((numb / factor) % 10) + '0');
		/*print the first digit, from the left*/
		factor = factor / 10;
	}
	_putchar((numb % 10) + '0'); /*print last digit*/
}

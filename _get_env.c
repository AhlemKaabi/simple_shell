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

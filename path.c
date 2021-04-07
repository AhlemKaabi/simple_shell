#include "shell.h"
/**
 * find_path - function that extacts the PATH variable.
 * @env: the environment variables.
 * Return: string that holds the environment variable PATH.
 */
char *find_path(char **env)
{
	char *path = "PATH=";
	int i, j;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5 ; j++)
		{
			if (path[j] != env[i][j])
			{
				break;
			}
			if (j == 4)
			{
				return (env[i]);
			}
		}
	}
	return (NULL);
}
/**
 * memory_work - function that copy each directory and
 * the command line into a new allocated space .
 * @directories: PATH splitted by ':'.
 * @command: the input command line.
 * Return: directory concatenated with the command line input.
 */
char *memory_work(char *directories, char *command)
{
	char *look_here;
	int i = 0;
	int j = 0;
	int command_len, directory_len, total_len;

	command_len = strlen(command);
	directory_len = strlen(directories);
	total_len = directory_len + command_len + 1;
	look_here = malloc(sizeof(char) * total_len);
	while (j < total_len)
	{
		for (i = 0; i <= directory_len && directories[i] != '\0'; i++)
		{
			look_here[i] = directories[i];
			j++;
		}
		look_here[j] = '/';
		j++;
		for (i = 0; i <= command_len; i++)
		{
			look_here[j] = command[i];
			j++;
		}
	}
	return (look_here);
}
/**
 * add_user_command - 1- adds the user command to the path
 * 2- check if the directory + command exist.
 * @cmd_line: the input command line.
 * @_path_splitted: PATH splitted by ':'.
 * @count: command count.
 * Return: 1 if the command exist
 */
int add_user_command(char *cmd_line, char **_path_splitted, int count)
{
	int i = 0;
	char *command_line;
	struct stat st;
	int exists_dir;
	char **command_line_splitted;

	while (_path_splitted[i] != NULL)
	{
		command_line = memory_work(_path_splitted[i], cmd_line);
		command_line_splitted = split_input(command_line, " \n");
		exists_dir = stat(command_line_splitted[0], &st);
		if (exists_dir == 0)
		{
			_exec_me(command_line_splitted, NULL, count);
			return (1);
		}
		i++;
	}
	return (-1);
}
/**
 * check_path - function that checks if the command exist in PATH
 * @lineptr: the input command line.
 * @env: the environment variables.
 * @count: command count.
 * Return: found or not.
 */
int check_path(char *lineptr, char **env, int count)
{
	char *PATH;
	char **PATH_splitted;
	int ret;

	PATH = find_path(env);
	PATH_splitted = split_input(PATH + 5, ":");
	ret = add_user_command(lineptr, PATH_splitted, count);
	if (ret == 1)
		return (1);
	else
		return (-1);
}

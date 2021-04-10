#include "shell.h"
/**
 * generate_command - concatenate every directory with command
 * @directory: directory from PATH
 * @command: user command.
 * Return: directory + command
*/
char *generate_command(char *directory, char *command)
{
	int i = 0;
	int j = 0;
	int command_len = 0;
	int directory_len = 0;
	int total_len = 0;
	char *final_cmd = NULL;

	command_len = strlen(command);
	directory_len = strlen(directory);
	total_len = directory_len + command_len + 2;
	final_cmd = malloc(sizeof(char) * total_len);
	if (final_cmd == NULL)
	{
		perror("Malloc error\n");
		free(final_cmd);
		exit(98);
	}
	while (j < total_len)
	{
		for (i = 0; i <= directory_len && directory[i] != '\0'; i++)
		{
			final_cmd[i] = directory[i];
			j++;
		}
		final_cmd[j] = '/';
		j++;
		for (i = 0; i <= command_len; i++)
		{
			final_cmd[j] = command[i];
			j++;
		}
	}
	return (final_cmd);
}
/**
 * add_user_command - check if program exists
 * @command: input taken from user.
 * @PATH_splitted: PATH env variable splitted by ':'.
 * Return: the result if the program exists or NULL
*/
char *add_user_command(char *command, char **PATH_splitted)
{

	char *final_cmd = NULL;
	int i = 0;
	int exists_program = 0;
	struct stat st;

	while (PATH_splitted[i] != NULL)
	{
		final_cmd = generate_command(PATH_splitted[i], command);
		i++;
		exists_program = stat(final_cmd, &st);
		if (exists_program == 0)
		{
			return (final_cmd);
		}
		else
		{
			free(final_cmd);
		}
	}
	return (NULL);
}
/**
 * check_path - handle PATH verification
 * @command_splitted: user command splitted
 * @count: will be sent to exec
 * Return: exists or not
**/
int check_path(char **command_splitted, int count)
{
	char *PATH = NULL;
	char **PATH_splitted;
	char *program_path;
	int executed = 0;

	PATH = find_path();
	PATH_splitted = split_input(PATH + 5, ":");
	program_path = add_user_command(command_splitted[0], PATH_splitted);
	if (program_path != NULL)
	{
		executed = _exec_me(program_path, command_splitted, NULL, count);
		if (executed == 1)
		{
			free(program_path);
			free_array(PATH_splitted);
			return (SUCCESS);
		}
	}
	free(program_path);
	free_array(PATH_splitted);
	return (FAILURE);
}

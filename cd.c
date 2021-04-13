#include "shell.h"

void cd_error(int count , char *Dir)
{
	write(1, "hsh: ", 5);
    print_number(count);
    write(1, ": cd", 4);
   	write(1, ": can't cd to ", 15);
	write(1, Dir, _strlen(Dir));
	write(1, "\n", 1);
}

void cd_function(char **cmd, int count)
{
	int path = 1;
	char buf[4096];
	char *old_path = NULL;
	char *curr_path = NULL;


	if (cmd[2] != NULL)
	{
		perror("error");
	}
	else
	{
		if (cmd[1] != NULL)
		{
			if (_strncmp(cmd[1], "-") == 0)
			{
				if(old_path == NULL)
				{
					path = chdir(_getenv("HOME="));
					if (path != 0)
						perror("Error: ");
				}
				else
				{
					path = chdir(old_path);
					if (path != 0)
						cd_error(count, cmd[1]);
				}
			}
			else
			{
				old_path = getcwd(buf, sizeof(buf));
				curr_path = cmd[1];
				path = chdir(curr_path);
				if (path != 0)
					cd_error(count, curr_path);
			}
		}
		if (cmd[1] == NULL)
		{
			path = chdir(_getenv("HOME="));
			if (path != 0)
			{
				perror("Error");
			}
		}
	}
}
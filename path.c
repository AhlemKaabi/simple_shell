#include "shell.h"
/* extract the Path environment variable */
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
                return(env[i]);
            }       
        }
    }
}

/*modify directories path*/
char *memory_work(char *directories, char *command)
{
    char *look_here;
    int i = 0;
    int j = 0;

    int command_len = strlen(command);
    int directory_len = strlen(directories);
    int total_len = directory_len + command_len + 1;
    look_here = malloc(sizeof(char) * total_len);
    while (j < total_len)
    {
        for (i = 0; i <= directory_len && directories[i] != '\0'; i++)
        {
            look_here[i] = directories[i]; 
            j++;
        }
        printf("look here variable : %s\n", look_here);
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

/*add user command line to the splitted path*/
char *add_user_command(char *cmd_line, char **_path_splitted)
{
    int i = 0;
    char *command_line;
    
    while ( _path_splitted[i] != NULL)
    {
        command_line = memory_work(_path_splitted[i], cmd_line);
        i++;
    }
	return(command_line);
}

/*check path + command line exist ? and execute*/
void check_command_line(char **command_line_splitted)
{	struct stat st;
    int exists_dir;

	exists_dir = stat(command_line_splitted[0], &st);
	if (exists_dir == 0)
	{
		execve(command_line_splitted[0], command_line_splitted, NULL);
	}
	else
	{
		printf("didn't found you executable :( \n");
	}
}

/*check path executed or not*/
int check_path(char *lineptr, char **env)
{
	char *PATH = find_path(env);
	char **PATH_splitted = split_input(PATH + 5, ":");
	char *command_line = add_user_command(lineptr, PATH_splitted);
	char **command_line_splitted = split_input(command_line, " ");
	check_command_line(command_line_splitted);
	if(check_command_line)
		return(0);
	else
		retun(-1);
}
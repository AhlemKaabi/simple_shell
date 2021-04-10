#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#define SUCCESS 1
#define FAILURE -1
extern char **environ;

/* function related to built-ins */
int check_builtins(char **command, char *input);
void _print_env(void);

/*helper functions */
char *find_path();
void free_array(char **array);
unsigned int _strlen(char *s);
int _strncmp(char *s1, char *s2);

/* parsing functions */
char *generate_command(char *directory, char *command);
char *add_user_command(char *command, char **PATH_splitted);
int check_path(char **command_splitted, int count);
char **split_input(char *line, char *delim);

/* main functions */
int _exec_me(char *program, char **command_splitted, char *input, int count);
void signal_handler(int sig);
void handle_input(char *input, int count);

#endif

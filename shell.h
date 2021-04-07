#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv, char **env);
int calc_len(char *str);
char **split_input(char *str, char *Delimiters);
int check_builtins(char **command, char **envp);
void _print_env(char **env);
int _exec_me(char **cmd, char *program_name, int count);
void signal_handler(int sig);

/*PATH*/
char *find_path(char **env);
char *memory_work(char *directories, char *command);
int add_user_command(char *cmd_line, char **_path_splitted, int count);
int check_command_line(char **command_line_splitted);
int check_path(char *lineptr, char **env, int count);

/* string manipulation functions */
int _strncmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strdup(char *duplicate);
int _putchar(char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif

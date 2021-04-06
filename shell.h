#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv, char **env);
int calc_len(char *str);
char **split_input(char *str, char *Delimiters);
int check_builtins(char **command, char **envp);
void _print_env(char **env);
int _exec_me(char **cmd);
void signal_handler(int sig);

/* string manipulation functions */
int _strncmp(char *s1, char *s2);


#endif

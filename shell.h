#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv, char **env);
void free_everything(char **string, int i);
int calc_len(char *str);
char **split_input(char *str);
int check_builtins(char *command, char **envp);
void _print_env(char **env);
#endif

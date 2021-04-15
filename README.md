# HSH: Holberton Shell
### Description
This project was written as part of the curriculum for Holberton School. It is a recreation of the command-line interpreter (shell). Functionally, this project  mirrors `sh` in a limited scope.

## Repo Contents

|   **File**    |  **Decription**                       |
|---------------|---------------------------------------|
|	`compile.sh`	|	Compile our simple shell	|
|	`valtest.sh`	 |	Run using valgrind |
|  `shell.h`	|  Header file: contains prototypes	|
|  `main.c`	|  Main file	|
|  `builtin.c` |  Functions to execute builtins|
|  `exec.c` |  Functions to handle the excution phase	|
|  `help.c`	| Functions to handle the help builtin |
|  `string_manip.c`  |  Custom string manipulation functions  |
|	`char_manip.c`	|	Custom character manipulation functions |
|  `_strtok.c`	    |  Custom strtok function	|
|  `helper_func.c`  |	Custom helper functions	|
|  `path.c`  | Functions for handling the PATH  |
|  `handle_input.c`  | Function to handle the command line input |

### How to Use
Clone repo
```
git clone https://github.com/alaedine07/simple_shell.git
```
Change directory to simple_shell
```
cd simple_shell/
```
Compile simply with
```
./compile.sh
```
or
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
### Interactive and Non-Interactive Mode
In interactive mode input is accepted from character input.
```
$ ls -l
total 148
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  3140 Apr 14 22:12 README.md
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   475 Apr 14 18:04 _get_env.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1117 Apr 14 21:25 _strtok.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  2054 Apr 14 21:05 builtins.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1587 Apr 14 18:04 cd
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1218 Apr 14 18:04 cd.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   328 Apr 14 21:05 char_manip.c
-rwxrwxr-x 1 ahlemkaabi ahlemkaabi    50 Apr 14 18:04 compile.sh
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1017 Apr 14 18:04 env
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1375 Apr 14 21:08 exec.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   151 Apr 14 18:04 exit
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  2052 Apr 14 21:15 handle_input.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  6414 Apr 14 18:04 help
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1655 Apr 14 18:04 help.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   617 Apr 14 18:04 help_help
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   652 Apr 14 21:18 helper_func.c
-rwxrwxr-x 1 ahlemkaabi ahlemkaabi 49104 Apr 14 21:21 hsh
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   495 Apr 14 21:02 main.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  3937 Apr 14 18:04 man_1_simple_shell
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  2177 Apr 14 21:03 path.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1748 Apr 14 21:21 shell.h
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1707 Apr 14 21:18 string_manip.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi    39 Apr 14 18:04 test_command
drwxrwxr-x 2 ahlemkaabi ahlemkaabi  4096 Apr 14 18:04 test_functions
-rwxrwxr-x 1 ahlemkaabi ahlemkaabi    91 Apr 14 18:04 valtest.sh
$ echo this is holberton simple shell
this is holberton simple shell
```

In non-interactive mode, the shell is run from commands being piped in. The subshell
is only opened as the command is carried out and closes at the completion of the command.

```
ahlemkaabi@ahlemkaabi-GL752VW:~/Desktop/simple_shell$ echo "ls -l" | ./hsh
total 152
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  4475 Apr 14 22:16 README.md
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   475 Apr 14 18:04 _get_env.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1117 Apr 14 21:25 _strtok.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  2054 Apr 14 21:05 builtins.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1587 Apr 14 18:04 cd
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1218 Apr 14 18:04 cd.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   328 Apr 14 21:05 char_manip.c
-rwxrwxr-x 1 ahlemkaabi ahlemkaabi    50 Apr 14 18:04 compile.sh
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1017 Apr 14 18:04 env
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1375 Apr 14 21:08 exec.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   151 Apr 14 18:04 exit
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  2052 Apr 14 21:15 handle_input.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  6414 Apr 14 18:04 help
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1655 Apr 14 18:04 help.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   617 Apr 14 18:04 help_help
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   652 Apr 14 21:18 helper_func.c
-rwxrwxr-x 1 ahlemkaabi ahlemkaabi 49104 Apr 14 21:21 hsh
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi   495 Apr 14 21:02 main.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  3937 Apr 14 18:04 man_1_simple_shell
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  2177 Apr 14 21:03 path.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1748 Apr 14 21:21 shell.h
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi  1707 Apr 14 21:18 string_manip.c
-rw-rw-r-- 1 ahlemkaabi ahlemkaabi    39 Apr 14 18:04 test_command
drwxrwxr-x 2 ahlemkaabi ahlemkaabi  4096 Apr 14 18:04 test_functions
-rwxrwxr-x 1 ahlemkaabi ahlemkaabi    91 Apr 14 18:04 valtest.sh

```
### Builtins and commands
Below are some of the builtin commands used, for further information please refer to the man page - accessed in terminal with:
```
man ./man_1_simple_shell
```
#### Builtins:
* `env` (Prints environmental variables)
* `exit` (Exit program)
* `help [command]` (Prints the help for command)

### Function and System Calls Used
`open`, `close`, `execve`, `exit`, `fork`, `free`, `getline`, `malloc`, `perror`, `wait`, `waitpid`, `write`, `stat`, `isatty`, `signal`.

## Notes
* This shell does not handle aliases, variables or history.
* This shell handle Ctrl+C: ./hsh do not quit when the user inputs ^C
* This shell handle Ctrl+D: ./hsh do quit when the user inputs ^D

### Bugs
Update the env variable OLDPWD and PWD using the `cd` builtin command.

### TO DOs
* Handling variables replacement.
* Handling the command seperator ; .
* Handling && and || logical operators.
* Handle the $? variable.
* Handle the $$ variable.
* Support the history feature.
* Support the file input.


### Authors
*Ahlem Kaabi*

*Alaedine Boufaden*

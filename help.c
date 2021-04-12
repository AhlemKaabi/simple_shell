#include "shell.h"

 void help(char **cmd)
 {
    if (cmd[2] == NULL)
    {
        if (_strncmp(cmd[1], "cd") == 0)
            read_textfile("cd", 1620);
        else if (_strncmp(cmd[1], "exit") == 0)
            read_textfile("exit", 147);
        else if (_strncmp(cmd[1], "env") == 0)
            read_textfile("env", 999);
        else if (_strncmp(cmd[1], "help") == 0)
            read_textfile("help_help", 599);
        else
        {
            write(1, "hsh: ", 5);
			write(1, cmd[0], _strlen(cmd[0]));
			write(1, ": no help topics match `", 24);
            write(1, cmd[1], _strlen(cmd[1]));
            write(1, "\'\n", 2);
        }
    }
    else
    {
        write(1, "hsh: ", 5);
        write(1, cmd[0], _strlen(cmd[0]));
        write(1, ": no help topics match `", 24);
        write(1, cmd[1], _strlen(cmd[1]));
        write(1, "\'\n", 2);
    }
 }
/**
 * read_textfile - function that reads a text file and prints
 * it to the POSIX standard output.
 *@filename: is the file to read
 *@letters: is the number of letters it sould read and print
 * Return: printed chars.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    size_t read_buf, printed;
    char *buf = malloc(sizeof(char) * letters);

    if (buf == NULL)
    {
        return (FAILURE);
    }
    if (filename == NULL)
        return (FAILURE);
    fd = open(filename, O_RDONLY); /*O_RDONLY : the flag to read only the file*/
    if (fd == -1)
    {
        free(buf);
        return (FAILURE);
    }
    read_buf = read(fd, buf, letters);
    if (read_buf == -1UL)
    {
        free(buf);
        return (FAILURE);
    }
    printed = write(STDOUT_FILENO, buf, read_buf);
    if (printed == -1UL)
    {
        return (FAILURE);
    }
    write(1, "\n", 1);
    free(buf);
    close(fd);
    return (printed);
}

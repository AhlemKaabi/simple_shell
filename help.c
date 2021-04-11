#include "shell.h"

 void help(char **cmd)
 {
    size_t read = 0;

    if (cmd[2] == NULL)
    {
        if (_strncmp(cmd[1], "cd") == 0)
        {
            read = read_textfile("cd", 1620);
            if (read == -1UL)
            {
                perror("bultin command doesnt exists");
            }
        }
        else if (_strncmp(cmd[1], "exit") == 0)
        {
            read = read_textfile("exit", 00);
            if (read == -1UL)
            {
                perror("bultin command doesnt exists");
            }
        }
        else if (_strncmp(cmd[1], "env") == 0)
        {
            read = read_textfile("env", 00);
            if (read == -1UL)
            {
                perror("bultin command doesnt exists");
            }
        }
        else if (_strncmp(cmd[1], "help") == 0)
        {
            read = read_textfile("help", 00);
            if (read == -1UL)
            {
              perror("bultin command doesnt exists");
            }
        }
        else
        {
            perror("bultin command doesnt exists");
        }
    }
    else
    {
        perror("only one command allowed");
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

// nanoshell.h

#ifndef NANOSHELL_H
#define NANOSHELL_H

#include <stdio.h> // input output fuctions (printf, fgets)
#include <stdlib.h> // memory management and system utilities (exit, malloc)
#include <unistd.h> // Unix system calls (chdir, getcwd, fork, execve)
#include <string.h> // string operations (strcmp, strcpy, strlen)
#include <sys/wait.h>   // wait functions (waitpid) - use when waiting for child processes
#include <sys/types.h>  // type definitions used by system calls (pid_t)

#define MAX_USER_INPUT 512 // constant to restrict user input length 
#define MAX_ARGUMENTS 16 // constant to restrict number of possible arguments

// draft function prototypes/declarations:

void print_prompt(void); // lets put it in a function for better design
void split_arguments(char *input, char *arguments[]); //parse user input and split it into separate arguments

int is_builtin(const char *command); // check if a command is built-in (cd, pwd, exit, env)
void builtin_cd(char *arguments[]); //change directory command
void builtin_pwd(void); // print working directory command
void builtin_env(void);  // display env variables command
char *find_in_path(const char *command);// search for an executable in the PATH env variable

void execute_external(char *arguments[]); // execute external programs (not built-in to our shell)

#endif
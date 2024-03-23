Atlas Simp

SYNOPSIS
Simple Shell is a simple UNIX command interpreter written in C language. 

DESCRIPTION
Atlas Simp will:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompy will display again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
It will handle errors.
The user can exit by pressing Ctrl+D.


Atlas Simp works similarly to bash and other basic shells.

The shell is compiled using an Ubuntu 22.04 LTS machine with 
-Wall -Werror -Wextra -pedantic -std=gnu89

FUNCTIONS:


cp: Copy a file to another file
ls: Lists contents of current directory



BUILT-INS:
exit: Exits the shell
env: Prints the current environment
setenv: Sets the environment
unsetenv: Unsets the environment


Return Value
Atlas Simp will run with a return value of 0, or a 1 if command failed.

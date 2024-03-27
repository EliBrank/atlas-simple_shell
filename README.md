
# Shelly


## SYNOPSIS

Shelly is a simple UNIX command interpreter written in C language. 

## DESCRIPTION

Display a prompt and wait for the user to type a command. A command line always ends with a new line. The prompt will display anew each time a command has been executed. The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features. The command lines are made only of one word. No arguments will be passed to programs. If an executable cannot be found, an error message will print and display the prompt again. It will handle errors. The user can exit by pressing Ctrl+D.

Shelly works similarly to bash and other basic shells.

The shell is compiled using an Ubuntu 22.04 LTS machine with 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89

## FUNCTIONS
| **Function** | **Result** |
| ----- | --------------------------- |
| cp | Copy a file to another file |
| ls | Lists contents of current directory |

## BUILT-INS

| **Built-ins** | **Result** |
| ----- | --------------------------- |
| echo | Displays user input |
| exit | Exits the shell |
| set | Sets the environment |
| unset | Unsets the environment |

## RETURN VALUE

Shelly will run with a return value of 0, or a 1 if command failed.

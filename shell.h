#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/* Define the structure for info_t */
typedef struct info {
    int argc;
    char **argv;
    int status;
    int err_num;
} info_t;

/* Define info_t or include the appropriate header file where info_t is defined */

/**
 * @file shell.h
 * @brief Header file for the shell program
 *
 * This header file contains prototypes for functions used in the shell program.
 */

/**
 * @brief Structure representing a built-in command and its handler function
 *
 * This structure represents a built-in command in the shell along with its
 * corresponding handler function. It consists of two fields: `type`, which
 * holds the string representation of the built-in command, and `func`, which
 * is a pointer to the function that handles the execution of the built-in command.
 * When a user enters a built-in command in the shell, the corresponding function
 * pointed to by `func` is invoked to execute the command. This structure is often
 * used in a table of built-in commands, where each entry maps a built-in command
 * string to its handler function.
 */
typedef struct builtin
{
    char *type;       /* The string representation of the built-in command */
    int (*func)(info_t *);  /* Pointer to the function handling the built-in command */
} builtin_table;

/* Macros */

/**
 * @brief Initialize a structure with default values
 *
 * This macro is used to initialize a structure of type `builtin_table`
 * with default values. It initializes all the fields of the structure  of type `builtin_table`
 * with default values. It initializes all the fields of the structure
 * to their default or initial values. The structure `builtin_table` is
 * typically used to associate built-in commands with their corresponding
 * functions. The macro sets all the fields of the structure to NULL or
 * zero, as appropriate, except for the `func` field, which represents
 * the function pointer to the function associated with the built-in command.
 * This macro helps ensure that the structure is properly initialized
 * before being used.
 */
#define INFO_INIT \
{ \
    NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
    0, 0, 0 \
}

/* Function prototypes */

/**
 * @brief Displays the shell prompt
 *
 * This function displays the prompt for the shell, indicating that it is ready
 * to accept user input.
 */
void show_prompt(void);

/**
 * @brief Custom print function to write to standard output
 * @param our_print_function Pointer to the string to be printed
 *
 * This function writes the specified string to the standard output (stdout).
 * It uses the write() system call to perform the writing operation. The string
 * to be printed is passed as a parameter to the function. The function calculates
 * the length of the string using strlen() function and then writes the string to
 * stdout using the write() system call. The function does not append a newline
 * character at the end of the string.
 */
void ed_print(const char *our_print_function);

/**
 * @brief Reads a command from standard input
 * @param command Buffer to store the command entered by the user
 * @param size Size of the buffer   *
 * This function reads a command from the standard input and stores it in the
 * specified buffer. It takes two parameters: the buffer to store the command
 * and the size of the buffer. The function uses fgets() to read the command
 * from stdin and stores it in the buffer. It ensures that the command is null-
 * terminated and removes the trailing newline character if present.
 */
void read_command(char *command, size_t size);

/**
 * @brief Executes the specified command
 * @param command Pointer to the command to be executed
 *
 * This function executes the specified command. It takes a pointer to the
 * command as a parameter. The function forks a new process using fork() and
 * then uses execve() to execute the command in the child process. If the
 * execution fails, the function prints an error message using ed_print().
 * The parent process waits for the child process to complete using wait().
 */
void execute_command(const char *command);

/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

#endif /* SHELL_H */


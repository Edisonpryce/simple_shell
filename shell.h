#ifndef SHELL_H
#define SHELL_H

/**
 * @file shell.h
 * @brief Header file for the shell program
 *
 * This header file contains prototypes for functions used in the shell program.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

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
 * @param size Size of the buffer
 *
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

#endif /* SHELL_H */


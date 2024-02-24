#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Description: This function serves as the main entry point for the shell program.
 *              It repeatedly prompts the user for a command, reads the command
 *              from the standard input, and then executes the command.
 *
 * Return: Always returns 0 to indicate successful termination of the program.
 */
int main(void)
{
    char command[128];  /* Buffer to store the command entered by the user */

    while (1) {
        show_prompt();   /* Display the shell prompt to the user */
        read_command(command, sizeof(command));  /* Read the command entered by the user */
        execute_command(command);   /* Execute the command entered by the user */
    }

    return 0;  /* Successful termination of the program */
}


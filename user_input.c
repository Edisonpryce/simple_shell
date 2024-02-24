#include "shell.h"

/**
 * read_command - Read a command from standard input
 * @command: Buffer to store the command read from standard input
 * @size: Size of the buffer
 *
 * Description:
 *    This function reads a command from the standard input and stores it in the
 *    specified buffer. It takes two parameters: a pointer to the buffer where the
 *    command will be stored and the size of the buffer. The function reads the
 *    command using the fgets function, which reads characters from the standard input
 *    until either a newline character or the end-of-file (EOF) is reached. If fgets
 *    encounters an error while reading input, it returns NULL. In that case, the
 *    function checks if the end-of-file has been reached. If EOF is reached, it prints
 *    a newline character using the ed_print function and exits with a success status.
 *    If an error occurs while reading input (other than EOF), it prints an error message
 *    using the ed_print function and exits with a failure status. After reading the
 *    command, the function removes any newline character from the command string using
 *    the strcspn function.
 */
void read_command(char *command, size_t size)
{
    /* Read command from standard input */
    if (fgets(command, size, stdin) == NULL) {
        /* Check if end-of-file (EOF) is reached */
        if (feof(stdin)) {
            /* Print newline character and exit with success status */
            ed_print("\n");
            exit(EXIT_SUCCESS);
        } else {
            /* Print error message and exit with failure status */
            ed_print("Error while reading input.\n");
            exit(EXIT_FAILURE);
        }
    }
    /* Remove newline character from command string */
    command[strcspn(command, "\n")] = '\0';
}


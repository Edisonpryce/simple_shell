#include "shell.h"

/**
 * ed_print - Custom print function to write to standard output
 * @our_print_function: Pointer to the string to be printed
 *
 * Description:
 *    This function writes the specified string to the standard output (stdout).
 *    It uses the write() system call to perform the writing operation. The string
 *    to be printed is passed as a parameter to the function. The function calculates
 *    the length of the string using strlen() function and then writes the string to
 *    stdout using the write() system call. The function does not append a newline
 *    character at the end of the string.
 */
void ed_print(const char *our_print_function)
{
    /* Write the string to the standard output */
    write(STDOUT_FILENO, our_print_function, strlen(our_print_function));
}


#include "shell.h"

/**
 * show_prompt - Display a shell prompt
 *
 * Description:
 *    This function displays a shell prompt to the user. The prompt is displayed as
 *    "Simple_Shell$". It internally calls the ed_print function to print the prompt
 *    string to the standard output. The function does not take any parameters and does
 *    not return any value.
 */
void show_prompt(void)
{
    ed_print("Simple_Shell$");
}


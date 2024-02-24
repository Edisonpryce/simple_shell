#include "shell.h"

/**
 * execute_command - Execute the specified command
 * @command: Pointer to the string containing the command to execute
 *
 * Description:
 *    This function executes the specified command by forking a new process and then
 *    calling the execve function to replace the child process with the specified command.
 *    It takes a pointer to the string containing the command as a parameter. Inside the
 *    function, a new process is created using the fork system call. If the fork fails,
 *    an error message is printed using the ed_print function, and the function exits
 *    with a failure status. If the fork succeeds and the process is the child process,
 *    the command string is tokenized into arguments, and the execve function is called
 *    to execute the command. If execve fails, an error message is printed, and the child
 *    process exits with a failure status. If the fork succeeds and the process is the
 *    parent process, it waits for the child process to finish executing.
 */
void execute_command(const char *command)
{
    pid_t child_pid = fork();  /* Create a new process */

    char *env[] = {NULL};  /* Array of environment variables for the child process */

    if (child_pid == -1) {
        /* Fork failed, print error message and exit */
        ed_print("ERROR FORKING PROCESS.\n");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        /* Child process */
        char *args[128];  /* Array of command arguments */
        int arg_count = 0;  /* Argument counter */

        /* Tokenize the command string into arguments */
        char *token = strtok((char *) command, " ");
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;  /* Null-terminate the argument list */

        /* Execute the command */
        execve(args[0], args, env);

        /* If execve fails, print error message and exit */
        ed_print("Error executing command.\n");
        exit(EXIT_FAILURE);
    } else {
        /* Parent process */
        wait(NULL);  /* Wait for the child process to finish executing */
    }
}


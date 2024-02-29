#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/* Define WRITE_BUF_SIZE and BUF_FLUSH macros */
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'

/* Define the structure for a linked list node */
typedef struct list_node {
    char *str;
    struct list_node *next;
} list_node_t;

/* Define the type for the linked list */
typedef list_node_t *list_t;

/* Define the structure for info_t */
typedef struct info {
    int argc;
    char **argv;
    int status;
    int err_num;
    int line_num; /* Define line_num member */
    list_t env; /* Added definition for env */
} info_t;

/* Function prototypes */

void print_list_str(list_t); /* Declaration of print_list_str function */

char *starts_with(const char *str, const char *prefix); /* Declaration of starts_with function */

void add_node_end(list_t *, const char *, int); /* Declaration of add_node_end function */

int _setenv(info_t *, const char *, const char *); /* Declaration of _setenv function */

void _unsetenv(info_t *, const char *); /* Declaration of _unsetenv function */

extern char **environ; /* Declaration of the environ variable */

/**
 * @brief Displays the shell prompt
 */
void show_prompt(void);

/**
 * @brief Custom print function to write to standard output
 * @param our_print_function Pointer to the string to be printed
 */
void ed_print(const char *our_print_function);

/**
 * @brief Reads a command from standard input
 * @param command Buffer to store the command entered by the user
 * @param size Size of the buffer
 */
void read_command(char *command, size_t size);

/**
 * @brief Executes the specified command
 * @param command Pointer to the command to be executed
 */
void execute_command(const char *command);

/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* atoi.c */
int interactive(info_t *);
int my_delim(char, char *);
int _myalpha(int);
int _atoi(char *);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_memory */
int bfree(void **ptr);

/* toem_parser */
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);

/*toem_realloc*/
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*toem_string1*/
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);

#endif /* SHELL_H */

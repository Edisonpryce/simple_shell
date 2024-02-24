#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
    (void)info; /* Unused parameter */
    return (0);
}

/**
 * unset_alias - unsets an alias by removing it from the list
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
    (void)info; /* Unused parameter */
    (void)str; /* Unused parameter */
    return (0);
}

/**
 * set_alias - sets an alias to a string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
    (void)info; /* Unused parameter */
    (void)str; /* Unused parameter */
    return (0);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
    (void)node; /* Unused parameter */
    return (0);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
    (void)info; /* Unused parameter */
    return (0);
}


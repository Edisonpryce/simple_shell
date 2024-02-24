#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 *
 * Return: Exits with a given exit status
 *         (0) if info->argc != 2
 */
int _myexit(info_t *info)
{
    int exitcheck;

    if (info && info->argc > 1)  /* If there is an exit argument */
    {
        exitcheck = atoi(info->argv[1]);
        if (exitcheck == 0 && info->argv[1][0] != '0')
        {
            info->status = 2;
            printf("Illegal number: %s\n", info->argv[1]);
            return (1);
        }
        info->err_num = exitcheck;
        return (-2);
    }
    info->err_num = -1;
    return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int _mycd(info_t *info)
{
    char *dir, buffer[1024];

    if (info && info->argc > 1)
    {
        if (strcmp(info->argv[1], "-") == 0)
        {
            dir = getenv("OLDPWD");
            if (!dir)
            {
                printf("No previous directory stored\n");
                return (1);
            }
            puts(dir);
            putchar('\n');
            chdir(dir);
        }
        else
        {
            if (chdir(info->argv[1]) == -1)
            {
                printf("can't cd to %s\n", info->argv[1]);
            }
        }
    }

    setenv("OLDPWD", getenv("PWD"), 1);
    setenv("PWD", getcwd(buffer, 1024), 1);

    return (0);
}

/**
 * _myhelp - prints a help message
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
    (void)info; /* Unused parameter */
    puts("help call works. Function not yet implemented");
    return (0);
}


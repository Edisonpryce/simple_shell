#include "shell.h"
#include <sys/stat.h>

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
    struct stat st;

    (void)info;
    if (!path || stat(path, &st) != 0) /* Check if stat() call failed */
        return (0);

    if (S_ISREG(st.st_mode)) /* Check if it's a regular file */
        return (1);
    return (0);
}


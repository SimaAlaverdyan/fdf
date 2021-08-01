#include "../include/fdf.h"

int     get_height(char *file)
{
    char    *line;
    int     fd;
    int     height;

    height = 0;
    fd = open(file, O_RDONLY, 0);

    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return(height);
}

void    read_file(t_utils *util, char *file)
{
    util->height = get_height(file);
}
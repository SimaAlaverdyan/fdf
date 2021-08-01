#ifndef FDF_H
#define FDF_H

#define BUFFER_SIZE 1

#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_utils
{
    int     width;
    int     height;
    int     **matrix;

    void    **mlx_ptr;
    void    **win_ptr;
}           t_utils;


int		        get_next_line(int fd, char **line);
size_t	        ft_strlen(const char *s);
#endif
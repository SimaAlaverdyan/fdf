#ifndef FDF_H
#define FDF_H

#define BUFFER_SIZE 1

#include <mlx.h>
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_utils
{
    int         width;
    int         height;
    int         **matrix;
    int         unitsize;
    int         color;
    int         z_scale;
    int         shiftx;
    int         shifty;
   	double	    angle;
    void        **mlx_ptr;
    void        **win_ptr;
}               t_utils;

int		        get_next_line(int fd, char **line);
size_t	        ft_strlen(const char *s);
void            read_file(t_utils *util, char *file);
int             key_pressed(int key, t_utils *util);
void            ft_exit(char *str);
void            draw(t_utils *util);
int             ft_check_extension(char *path, char *ext);
int		        red_cross(int key, t_utils *util);
void            freeMatrix(t_utils *util);
#endif
#include "../include/fdf.h"
#include <math.h>

int     Max(float a, float b)
{
    return(a > b ? a : b);
}

void    makeIsometric(float *x, float *y, int z, double angle)
{
    *x = (*x - *y) * cos(angle);
    *y = (*x + *y) * sin(angle) - z;
}

void    zoom(float *x, float *y, float *x1, float *y1, 
int *z, int *z1, t_utils *util)
{
    *x *= util->unitsize;
    *y *= util->unitsize;
    *x1 *= util->unitsize;
    *y1 *= util->unitsize;
    *z *= util->z_scale;
    *z1 *= util->z_scale;
}

void    join_two_points(float x, float y, float x1, float y1, t_utils *util) //Bresenham's line algorithm
{
    float       x_step;
    float       y_step;
    int         max;
    int         z;
    int         z1;
    
    z = util->matrix[(int)y][(int)x];
    z1 = util->matrix[(int)y1][(int)x1];
    //---------zoom with unitsize--------
    zoom(&x, &y, &x1, &y1, &z, &z1, util);

    //----------put color----------------
    util->color = (z || z1) ? 0x4f039a : 0xffffff;
    
    ///----------make magic effect--------
    makeIsometric(&x, &y, z, util->angle);
    makeIsometric(&x1, &y1, z1, util->angle);

    x += util->shiftx;
    y += util->shifty;
    x1 += util->shiftx;
    y1 += util->shifty;

    //----------calculate steps-----------
    x_step = x1 - x;
    y_step = y1 - y;
    max = Max(fabsf(x_step), fabsf(y_step));
    x_step /= max;
    y_step /= max;

    while((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(util->mlx_ptr, util->win_ptr, x, y, util->color);
        x += x_step;
        y += y_step;
    }
}

void    draw(t_utils *util)
{
    int     i;
    int     j;

    i = 0;
    while(i < util->height)
    {
        j = 0;
        while(j < util->width)
        {
            if(j < util->width - 1)
                join_two_points(j, i, j + 1, i, util);
            if(i < util->height - 1)
                join_two_points(j, i, j, i + 1, util);
            j++;
        }
        i++;
    }
    mlx_string_put(util->mlx_ptr, util->win_ptr, 5, 5, 0x00FAFF, "Zoom In(+) Zoom Out(-) Up(up button) Down(down button) Right(->) Left(<-)   ");
    mlx_string_put(util->mlx_ptr, util->win_ptr, 5, 25, 0x00FAFF, "angle+(4) angle-(6) scale+(8) scale-(2)");
}
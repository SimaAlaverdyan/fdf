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

void    join_two_points(t_utils a, t_utils b/*float x, float y*/ , t_utils *util) //Bresenham's line algorithm
{
    float   x_step;
    float   y_step;
    int     max;
    int     z;
    int     z1;
    
    z = util->matrix[(int)a.y][(int)a.x];
    z1 = util->matrix[(int)b.y][(int)b.x];

    //---------zoom with unitsize--------
    x *= util->unitsize;
    y *= util->unitsize;
    x1 *= util->unitsize;
    y1 *= util->unitsize;

    util->x = x;
    util->y = y;
    util->z = z;

    
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
    // int     i;
    // int     j;

    util->y = 0;
    while(util->y < util->height)
    {
        util->x = 0;
        while(util->x < util->width)
        {
            if(util->x < util->width - 1)
                join_two_points(util->x, util->y, util->x + 1, util->y, util);
            if(util->y < util->height - 1)
                join_two_points(util->x, util->y, util->x, util->y + 1, util);
            util->x++;
        }
        util->y++;
    }
}
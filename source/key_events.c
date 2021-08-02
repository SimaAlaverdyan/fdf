#include "../include/fdf.h"

int     key_pressed(int key, t_utils *util)
{
    if (key == 53)
		exit(0);
    if (key == 126) {
        util->shifty -= 20;
    }
    else if(key == 125)
    {
        util->shifty += 20;
    }
    else if(key == 124)
    {
        util->shiftx += 20;
    }
    else if(key == 123)
    {
        util->shiftx -= 20;
    }
    else if (key == 91)
    {
        util->angle += 0.05;
    }
    // else if(key ==  || key == 28 )

    
    mlx_clear_window(util->mlx_ptr, util->win_ptr);
    draw(util);
    return(0);
}
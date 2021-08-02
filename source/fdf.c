#include "../include/fdf.h"

int     main(int argc, char **argv)
{
    t_utils     *util;

    util = (t_utils *)malloc(sizeof(t_utils));
    if (argc == 2)
    {
        read_file(util, argv[1]);

        util->unitsize = 20;
        util->angle = 0.8;
        util->z_scale = 1;
        util->mlx_ptr = mlx_init();
        util->win_ptr = mlx_new_window(util->mlx_ptr, 1000, 1000, "FDF");

        draw(util);
    
        mlx_key_hook(util->win_ptr, key_pressed, util);
        mlx_loop(util->mlx_ptr);
    }
    return (0);
}
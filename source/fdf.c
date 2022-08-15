#include "../include/fdf.h"

int main(int argc, char **argv)
{
    t_utils *util;

    util = (t_utils *)malloc(sizeof(t_utils));
    if (argc == 2)
    {
        if (!(ft_check_extension(argv[1], ".fdf")))
            ft_exit("Invalid file format.");
        read_file(util, argv[1]);

        util->unitsize = 15;
        util->angle = 0.8;
        util->z_scale = 1;
        util->mlx_ptr = mlx_init();
        util->win_ptr = mlx_new_window(util->mlx_ptr, 3000, 1000, "FDF");

        draw(util);
        mlx_key_hook(util->win_ptr, key_pressed, util);
        mlx_hook(util->win_ptr, 17, (1L << 17), red_cross, &util);
        mlx_loop(util->mlx_ptr);
    }
    else
        ft_exit("Arguments Error");
    free(util);
    freeMatrix(util);
    return (0);
}
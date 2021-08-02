#include "../include/fdf.h"

int     main(int argc, char **argv)
{
    t_utils     *util;
    int         i;
    int         j;

    util = (t_utils *)malloc(sizeof(t_utils));
    if (argc == 2)
    {
        read_file(util, argv[1]);
        i = 0;
        while(i < util->height)
        {
            j = 0;
            while (j < util->width)
            {
                printf("%3d", util->matrix[i][j]);
                j++;
            }
            printf("\n");
            i++;
        }
    }
    return (0);
}
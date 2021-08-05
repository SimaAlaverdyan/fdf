#include "../include/fdf.h"

void ft_exit(char *str)
{
    write(1, "[fdf] ", 7);
    ft_putstr_fd(str, 1);
    write(1, "\n", 1);
    exit(0);
}


int     ft_check_extension(char *path, char *ext)
{
	int	pathlen;
	int	extlen;

	pathlen = ft_strlen(path);
	extlen = ft_strlen(ext);
	if (!(extlen == 4) || !(pathlen > 4))
		return (0);
	return (*(path + pathlen - 1) == *(ext + extlen - 1)
		&& *(path + pathlen - 2) == *(ext + extlen - 2)
		&& *(path + pathlen - 3) == *(ext + extlen - 3)
		&& *(path + pathlen - 4) == *(ext + extlen - 4));
}
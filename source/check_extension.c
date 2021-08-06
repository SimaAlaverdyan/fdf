#include "../include/fdf.h"

void ft_exit(char *str)
{
    write(1, "[fdf] ", 7);
    ft_putstr_fd(str, 1);
    write(1, "\n", 1);
    exit(0);
}

int		red_cross(int key, t_utils *util)
{
	(void)key;
	(void)util;
	exit(0);
}

int 	isfile_exist(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1) {
		return (0);
	}
	close(fd);
	return(1);
}

int     ft_check_extension(char *path, char *ext)
{
	int	pathlen;
	int	extlen;
	if(!(isfile_exist(path)))
		return(0);
	pathlen = ft_strlen(path);
	extlen = ft_strlen(ext);

	if (!(extlen == 4) || !(pathlen > 4))
		return (0);
	return (*(path + pathlen - 1) == *(ext + extlen - 1)
		&& *(path + pathlen - 2) == *(ext + extlen - 2)
		&& *(path + pathlen - 3) == *(ext + extlen - 3)
		&& *(path + pathlen - 4) == *(ext + extlen - 4));
}
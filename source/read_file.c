#include "../include/fdf.h"

int		ft_wordcount(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

int     get_height(char *file)
{
    char    *line;
    int     fd;
    int     height;

    height = 0;
    fd = open(file, O_RDONLY, 0);

    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return(height);
}

int     get_width(char *file)
{
    char    *line;
    int     fd;
    int     width;

    width = 0;
    fd = open(file, O_RDONLY, 0);

    get_next_line(fd, &line);
    width = ft_wordcount(line, ' ');
    close(fd);
    
    return(width);
}

void    fill_matrix(int *line1, char *line)
{
    char    **numbers;
    int     i;

    i = 0;
    numbers = ft_split(line, ' ');

    while(numbers[i])
    {
        line1[i] = ft_atoi(numbers[i]);
        free(numbers[i]);
        i++;    
    }
    free(numbers);
}

void    read_file(t_utils *util, char *file)
{
    int     fd;
    int     i;
    char    *line;

    util->height = get_height(file);
    util->width = get_width(file);

    util->matrix = (int **)malloc(sizeof(int *) * (util->height + 1));
    i = 0;
    while(i <= util->height)
        util->matrix[i++] = (int *)malloc(sizeof(int) * (util->width + 1));
    
    fd = open(file, O_RDONLY);
    i = 0;

    while(get_next_line(fd, &line))
    {
        fill_matrix(util->matrix[i], line);
        free(line);
        i++;
    }
    util->matrix[i] = NULL;
    close(fd);
}

void    freeMatrix(t_utils *util)
{
    for(int i = 0; i < util->height; i++)
        free(util->matrix[i]);
    free(util->matrix);
}

#include "ft_read_map.h"
#include "ft_atoi.h"
#include <unistd.h>
#include <stdlib.h>

char	read_number(int fd, int *num)
{
	char	buf[10];
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) == 1 && is_digit(c))
	{
		buf[i] = c;
		++i;
	}
	if (i == 0)
		return (0);
	buf[i] = '\0';
	return (ft_atoi(buf, num) ? c : 0);
}

bool	read_char(int fd, t_map *map, char *c)
{
	return (read(fd, c, 1) == 1 && (*c == map->empty ||
	*c == map->obstacle || *c == '\n'));
}

bool	read_helper(t_map *map, int i, int width, char c)
{
	map->map[i][width] = c;
	return (!(map->width > 0 && width > map->width));
}

bool	ft_read_chars(int fd, t_map *map, char c, int width)
{
	int i;

	map->width = -1;
	i = 0;
	width = 0;
	while (i < map->height)
	{
		if (!read_char(fd, map, &c))
			return (false);
		if (c == '\n')
		{
			if (map->width == -1)
				map->width = width;
			if (width == 0 || width != map->width ||
			++i == map->height)
				return (width != 0 && width == map->width && i == map->height);
			map->map[i] = malloc(width);
			width = 0;
		}
		else if (!read_helper(map, i, width++, c))
			return (false);
	}
	return (true);
}

bool	ft_read_map(int fd, t_map *map)
{
	char	c;
	int		cur_height;

	if (!(map->empty = read_number(fd, &map->height)) || map->height <= 0)
		return (false);
	read(fd, &map->obstacle, 1);
	read(fd, &map->full, 1);
	read(fd, &c, 1);
	if (map->empty == map->obstacle || map->empty == map->full ||
	map->obstacle == map->full || c != '\n')
		return (false);
	map->map = malloc(sizeof(char*) * map->height);
	map->map[0] = malloc(10000);
	return (ft_read_chars(fd, map, 0, 0));
}

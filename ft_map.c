/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:00:44 by evada             #+#    #+#             */
/*   Updated: 2020/09/30 00:12:26 by evada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>
#include <unistd.h>

void	**ft_alloc_map(int w, int h, int s)
{
	void	**ans;
	int		i;

	ans = malloc(sizeof(void*) * h);
	i = -1;
	while (++i < h)
	{
		ans[i] = malloc(w * s);
	}
	return (ans);
}

void	free_map(void **map, int w, int h)
{
	int i;

	i = -1;
	while (++i < h)
		free(map[i]);
	free(map);
}

void	print_map(char **ans, int w, int h)
{
	int	i;

	i = -1;
	while (++i < h)
	{
		write(STDOUT_FILENO, ans[i], w);
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	paint_map(t_map *map, t_request *req, int **gmap)
{
	int	a;
	int	b;

	a = req->i - 1;
	while (++a <= req->i + req->k)
	{
		b = req->j - 1;
		while (++b <= req->j + req->k)
		{
			map->map[a][b] = map->full;
		}
	}
	print_map(map->map, map->width, map->height);
	free_map((void**)gmap, map->width, map->height);
}

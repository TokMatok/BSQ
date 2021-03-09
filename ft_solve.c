
#include "ft_solve.h"
#include <stdbool.h>
#include <stdio.h>

bool	is_possible(t_request *r)
{
	if (r->i + r->k >= r->h || r->j + r->k >= r->w)
		return (false);
	return (r->map[r->i + r->k][r->j + r->k] -
	(r->j == 0 ? 0 : r->map[r->i + r->k][r->j - 1]) -
	(r->i == 0 ? 0 : r->map[r->i - 1][r->j + r->k]) +
	(r->i == 0 || r->j == 0 ? 0 : r->map[r->i - 1][r->j - 1]) == 0);
}

char	**generate_map(t_map *map)
{
	char	**nmap;
	int		i;
	int		j;

	nmap = (char**)ft_alloc_map(map->width, map->height, 1);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			nmap[i][j] = (map->map[i][j] == map->obstacle);
		}
	}
	return (nmap);
}

int		**precompute(t_map *map)
{
	int		**ans;
	char	**nmap;
	int		i;
	int		j;

	nmap = generate_map(map);
	ans = (int**)ft_alloc_map(map->width, map->height, sizeof(int));
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (i == 0)
				ans[i][j] = (j == 0) ? nmap[i][j] : ans[i][j - 1] + nmap[i][j];
			else if (j == 0)
				ans[i][j] = ans[i - 1][j] + nmap[i][j];
			else
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1] -
				ans[i - 1][j - 1] + nmap[i][j];
		}
	}
	free_map((void**)nmap, map->width, map->height);
	return (ans);
}

void	init_request(t_request *req, t_map *map, int **gmap)
{
	req->k = 0;
	req->w = map->width;
	req->h = map->height;
	req->map = gmap;
}

void	solve(t_map *map, int i)
{
	int			**gmap;
	t_request	req;
	t_request	best_req;
	int			j;

	gmap = precompute(map);
	init_request(&req, map, gmap);
	best_req.k = -1;
	i = -1;
	while (++i < map->height)
	{
		req.i = i;
		j = -1;
		while (++j < map->width)
		{
			req.j = j;
			while (is_possible(&req))
			{
				best_req = req;
				++req.k;
			}
		}
	}
	if (best_req.k != -1)
		paint_map(map, &best_req, gmap);
}

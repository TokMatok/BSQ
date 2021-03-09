
#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct	s_map {
	int		width;
	int		height;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
}				t_map;

typedef struct	s_request {
	int i;
	int j;
	int k;
	int **map;
	int w;
	int h;
}				t_request;

void			**ft_alloc_map(int w, int h, int s);
void			free_map(void **map, int w, int h);
void			print_map(char **ans, int w, int h);
void			paint_map(t_map *map, t_request *req, int **gmap);

#endif

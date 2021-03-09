/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:03:44 by evada             #+#    #+#             */
/*   Updated: 2020/09/30 00:19:06 by evada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_map.h"
#include "ft_map.h"
#include "ft_solve.h"
#include <unistd.h>
#include <fcntl.h>

void	process_file(int fd)
{
	t_map map;

	if (fd == -1 || !ft_read_map(fd, &map))
	{
		write(STDOUT_FILENO, "map error\n", 10);
		return ;
	}
	solve(&map, 0);
	free_map((void**)map.map, map.width, map.height);
}

int		main(int argc, char **argv)
{
	int i;
	int fd;

	i = 0;
	if (argc == 1)
	{
		process_file(STDIN_FILENO);
		return (0);
	}
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		process_file(fd);
		if (i < argc - 1)
			write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

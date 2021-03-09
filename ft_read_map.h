/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:02:47 by evada             #+#    #+#             */
/*   Updated: 2020/09/30 00:02:52 by evada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_MAP_H
# define FT_READ_MAP_H
# include <stdbool.h>
# include "ft_map.h"

bool	ft_read_map(int fd, t_map *map);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:00:59 by evada             #+#    #+#             */
/*   Updated: 2020/09/30 00:01:03 by evada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOI_H
# define FT_ATOI_H
# include <stdbool.h>

bool	ft_isspace(char c);
bool	ft_atoi(char *str, int *num);
bool	is_digit(char c);

#endif

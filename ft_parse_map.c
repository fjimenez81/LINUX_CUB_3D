/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:48:55 by fernando          #+#    #+#             */
/*   Updated: 2020/08/26 21:05:46 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_valid_map(t_info *info_map, int y, int x)
{
	if (((info_map->map[y][x] == '0' || info_map->map[y][x] == '2') &&
	(x == (info_map->len_x - 1) || y == (info_map->len_y - 1) ||
	x == 0 || y == 0)))
	{
		ft_management_error(5, "");
		exit(0);
	}
	info_map->map[y][x] = info_map->map[y][x] == '0' ? '3' : '1';
	if (y != (info_map->len_y - 1))
		if (info_map->map[y + 1][x] == '0')
			ft_valid_map(info_map, y + 1, x);
	if (y != 0)
		if (info_map->map[y - 1][x] == '0')
			ft_valid_map(info_map, y - 1, x);
	if (x != (info_map->len_x - 1))
		if (info_map->map[y][x + 1] == '0')
			ft_valid_map(info_map, y, x + 1);
	if (x != 0)
		if (info_map->map[y][x - 1] == '0')
			ft_valid_map(info_map, y, x - 1);
}

int		ft_parse_map_line(t_info *info_map)
{
	int i;
	int j;

	i = -1;
	while (info_map->map[++i])
	{
		j = -1;
		while (info_map->map[i][++j])
		{
			if (info_map->map[i][j] == 'N' ||
				info_map->map[i][j] == 'S' ||
				info_map->map[i][j] == 'E' ||
				info_map->map[i][j] == 'W' ||
				info_map->map[i][j] == ' ')
				info_map->map[i][j] = '0';
		}
	}
	return (1);
}

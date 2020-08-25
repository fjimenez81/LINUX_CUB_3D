/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 15:25:07 by fernando          #+#    #+#             */
/*   Updated: 2020/08/24 16:51:01 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_extension(char *s)
{
	int		i;
	int		j;
	char	*check;

	i = 0;
	check = ".cub";
	while (s[i])
	{
		j = 0;
		while (s[i + j] == check[j] && check[j])
		{
			if (s[i + j + 1] == '\0' && check[j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_open_texture(t_info *info_map)
{
	if ((open(info_map->north_t, O_RDONLY)) == -1)
		return (0);
	if ((open(info_map->south_t, O_RDONLY)) == -1)
		return (0);
	if ((open(info_map->east_t, O_RDONLY)) == -1)
		return (0);
	if ((open(info_map->west_t, O_RDONLY)) == -1)
		return (0);
	return (1);
}

int		ft_parse_info(t_info *info_map)
{
	if (info_map->rx <= 0 || info_map->ry <= 0)
	{
		ft_management_error(9, "Error\nThe resolution is not correct\n");
		return (0);
	}
	info_map->rx = info_map->rx > 1920 ? 1920 : info_map->rx;
	info_map->ry = info_map->ry > 1080 ? 1080 : info_map->ry;
	if (info_map->colorf < 0 || info_map->colorc < 0)
	{
		ft_putstr_fd("Error\nThe color of ", 1);
		ft_management_error(9, "floor or roof must to be >= 0 && < 256\n");
		return (0);
	}
	if (!ft_check_open_texture(info_map))
	{
		ft_management_error(9, "Error\nopen(texture) failed\n");
		return (0);
	}
	return (1);
}

int		ft_check_map(t_info *info_map)
{
	int	i;
	int	x;

	i = 0;
	while (info_map->map[i])
	{
		x = 0;
		while (info_map->map[i][x])
		{
			if (info_map->map[i][x] != '0' && info_map->map[i][x] != '1' &&
			info_map->map[i][x] != '2' && info_map->map[i][x] != 'N' &&
			info_map->map[i][x] != 'S' && info_map->map[i][x] != 'E' &&
			info_map->map[i][x] != 'W' && info_map->map[i][x] != ' ')
				return (ft_management_error(6, ""));
			if (info_map->map[i][x] == 'N' || info_map->map[i][x] == 'S' ||
			info_map->map[i][x] == 'E' || info_map->map[i][x] == 'W')
				if (!(ft_get_pos_player(info_map, i, x)))
					return (0);
			x++;
		}
		i++;
	}
	if (info_map->player_start == '0')
		return (ft_management_error(8, ""));
	return (1);
}

int		ft_parse_management(t_info *info_map)
{
	if (!ft_parse_info(info_map))
		return (0);
	if (!ft_check_map(info_map))
		return (0);
	if (!ft_parse_map_line(info_map))
	{
		ft_management_error(5, "");
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:48:55 by fernando          #+#    #+#             */
/*   Updated: 2020/08/25 21:07:15 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_line_three_aux(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == '2')
	{
		if (map[i + 1][j] == ' ' ||
			map[i - 1][j] == '\0' ||
			map[i - 1][j] == '$' ||
			map[i + 1][j] == '$' ||
			map[i][j + 1] == ' ' ||
			map[i][j - 1] == ' ' ||
			(map[i][j - 2] == ' ' &&
			map[i][j - 1] == ' '))
			return (0);
	}
	if (map[i][j] == '#' && map[i - 1][j] == '$')
		return (0);
	return (1);
}

static int	ft_parse_line_three(char **map)
{
	int i;
	int j;
	i = -1;
	while (map[++i])
		ft_putendl_fd(map[i], 1);
	i = ft_len_tab(map) - 2;
	while (i > 0)
	{
		j = ft_strlen(map[i]) - 1;
		while (j > 0)
		{
			if (!ft_line_three_aux(map, i, j))
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

static	int	ft_parse_line_two(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			ft_check_map_space(map, i, j);
			if (map[i][0] != '1')
				ft_check_first_space(map, i);
			if (map[i][j] == '0' || map[i][j] == '2')
			{
				if ((map[i][j + 1] == ' ' &&
				(map[i][j + 2] == '\0' || map[i][j + 2] == ' ')) ||
				map[i - 1][j] == ' ' ||
				map[i][j + 1] == '\0' ||
				map[i + 1][j] == '\0')
					return (0);
			}
		}
	}
	return (1);
}

static	int	ft_parse_line_one(char **map)
{
	int i;
	int len;

	i = -1;
	while (map[0][++i])
	{
		ft_check_map_space(map, 0, i);
		if ((map[0][i] == '2' || map[0][i] == '0') &&
			map[0][i + 1] == '1' && map[1][i] != '1')
			return (0);
	}
	i = -1;
	len = ft_len_tab(map) - 1;
	while (map[len][++i])
	{
		ft_check_map_space(map, len, i);
		//if ((map[len][i] == '2' || map[len][i] == '0') &&
		 	//map[len][i] == '1' && map[len][i + 1] == '1')
			//return (0);
	}
	len = -1;
	while (map[++len])
	{
		i = ft_strlen(map[len]);
		while (map[len][--i])
		{
			if (i == (int)ft_strlen(map[len]) - 1 && map[len][i] == '0' &&
				map[len][i - 1] == '1')
				map[len][i - 1] = '$';
			if (map[len][i] != '1')
				map[len][i] = '$';
			if (len > 0 && map[len][i] == '1' &&
				map[len - 1][i] != ' ')
				break ;
		}
	}
	return (1);
}

int			ft_parse_map_line(t_info *info_map)
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
				info_map->map[i][j] == 'W')
				info_map->map[i][j] = '0';
		}
	}
	if (!ft_parse_line_one(info_map->map))
		return (0);
	if (!ft_parse_line_two(info_map->map))
		return (0);
	if (!ft_parse_line_three(info_map->map))
		return (0);
	return (1);
}

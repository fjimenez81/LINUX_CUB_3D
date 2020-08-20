/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:48:55 by fernando          #+#    #+#             */
/*   Updated: 2020/08/20 13:58:11 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	ft_parse_line_three(char **map)
{
	int i;
	int j;

	i = ft_len_tab(map) - 2;
	while (i > 0)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '2')
			{
				if (map[i][0] == '0' || map[i][0] == '2')
					return (0);
				if (map[i + 1][j] == ' ' ||
				map[i + 1][j + 1] == ' ' ||
				map[i - 1][j + 1] == ' ' ||
				map[i - 1][j + 1] == '\0')
					return (0);
			}
			j++;
		}
		i--;
	}
	return (1);
}

static	int	ft_parse_line_two(char **map)
{
	int i;
	int j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '2')
			{
				if (map[i][0] == '0' || map[i][0] == '2')
					return (0);
				if (map[i - 1][j] == ' ' ||
				map[i - 1][j - 1] == ' ' ||
				map[i + 1][j + 1] == '\0' ||
				map[i + 1][j - 1] == ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static	int	ft_parse_line_one(char **map)
{
	int i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == '2' || map[0][i] == '0')
			return (0);
		else if (map[0][i] == ' ')
		{
			if (map[1][i] == '0')
				return (0);
		}
		i++;
	}
	return (1);
}

int			ft_parse_map_line(t_info *info_map)
{
	if (!ft_parse_line_one(info_map->map))
		return (0);
	if (!ft_parse_line_two(info_map->map))
		return (0);
	if (!ft_parse_line_three(info_map->map))
		return (0);
	return (1);
}

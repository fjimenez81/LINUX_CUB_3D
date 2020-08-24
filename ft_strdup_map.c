/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 18:17:36 by fernando          #+#    #+#             */
/*   Updated: 2020/08/24 12:54:58 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_first_space(char **map, int i)
{
	int j;

	j = -1;
	while (map[i][++j] == ' ')
	{
		if (map[i][j] == ' ' &&
			(map[i][j + 1] == '0' || map[i][j + 1] == '2'))
			return (0);
	}
	return (1);
}

void	ft_check_map_space(char **map, int i, int j)
{
	if (map[i][j] != ' ' && map[i][j + 1] == ' ' &&
		i < ft_len_tab(map) - 1)
	{
		if (map[i][j - 1] == '0' && map[i + 1][j + 1] == '0')
			map[i][j + 1] = '0';
	}
	if (map[i][j] == ' ' && map[i][j + 1] != ' ' &&
		map[i][j + 2] == ' ' && i < ft_len_tab(map) - 3)
	{
		if (map[i + 1][j] == ' ' && map[i + 1][j + 1] == ' ' &&
			map[i + 1][j + 2] == ' ')
			map[i + 1][j + 1] = '0';
	}
}

void	ft_change_player(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' ||
				map[i][j] == 'S' ||
				map[i][j] == 'E' ||
				map[i][j] == 'W')
				map[i][j] = '0';
		}
	}
}

void	ft_check_map_space_two(char **map, int i, int j)
{
	if (map[i][j] == ' ' && (i == 0 || i == ft_len_tab(map) - 1))
		map[i][j] = '1';
	if (map[i][j] == '1' && map[i][j + 1] == ' ' &&
		(i > 0 && i < ft_len_tab(map) - 1))
		map[i][j + 1] = '0';
	if (map[i][j] != ' ' && map[i][j + 1] == ' ' &&
		(i > 0 && i < ft_len_tab(map) - 1))
	{
		if (map[i][j] == '2')
		{
			map[i][j] = '0';
			map[i][j + 1] = '2';
		}
		else
			map[i][j + 1] = '0';
	}
	if (map[i][j] == '1' && map[i][j + 2] == '2')
	{
		map[i][j + 1] = '2';
		map[i][j + 2] = '0';
	}
}

char	*ft_strdup_map(char *s)
{
	int		i;
	int		j;
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
		dest[j++] = s[i];
	dest[j] = '\0';
	free(s);
	return (dest);
}

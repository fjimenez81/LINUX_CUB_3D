/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 18:17:36 by fernando          #+#    #+#             */
/*   Updated: 2020/08/25 20:38:27 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_check_first_space(char **map, int i)
{
	int j;

	j = -1;
	while (map[i][++j] != '1')
		map[i][j] = '$';
	j = -1;
	while (map[i][++j] == '$')
		if (map[i][j + 1] == '0' || map[i][j + 1] == '2')
			map[i][j + 1] = '$';
}

static void	ft_space_aux(char **map, int i, int j)
{
	if (i < ft_len_tab(map) - 1 && map[i][j] == '#' && map[i + 1][j] == ' ')
		map[i + 1][j + 1] = '0';
	if (i < ft_len_tab(map) - 1 && map[i][j] == '$' && map[i + 1][j] == '#')
		map[i + 1][j] = '0';
	if (i == 0 && map[i][j] == '1' && map[i][j + 1] == ' ' &&
		map[i + 1][j + 1] == ' ')
		map[i + 1][j + 1] = '0';
	if (i == 0 && map[i][j] == '1' && map[i][j + 1] != '1' &&
		map[i + 1][j + 1] == '1')
		map[i][j + 1] = '1';
	if ((i == ft_len_tab(map) - 1 && map[i][j] == '0' &&
		map[i - 1][j] == '1') || (i == 0 && map[i][j] == '0' &&
		map[i + 1][j] == '1'))
		map[i][j] = '1';
	if (i == 0 && (map[0][0] == '0' || map[0][0] == '2'))
		map[0][0] = ' ';
}

void		ft_check_map_space(char **map, int i, int j)
{
	if ((i > 0 && i < ft_len_tab(map) - 1 && map[i][0] == '1' &&
		map[i][1] == ' ') && map[i][2] != '0' && map[i][2] == '2')
		map[i][0] = '$';
	if (j == (int)ft_strlen(map[i]) - 1 && map[i][j] == '0' &&
		map[i][j - 1] == '1')
		map[i][j] = '$';
	if (i > 0 && map[i][j] == ' ' && map[i][j - 1] == '1' &&
		map[i][j + 1] == '1')
		map[i][j] = '$';
	if (i < ft_len_tab(map) - 1 && map[i][j] == '1' && map[i][j + 1] == '0' &&
		map[i + 1][j + 1] == '$')
		map[i][j + 1] = ' ';
	if (i < ft_len_tab(map) - 1 && i > 0 && map[i][j] != ' ' &&
		map[i][j + 1] == ' ' && map[i + 1][j + 1] != '$')
		map[i][j + 1] = '#';
	if (i < ft_len_tab(map) - 1 && map[i][j] == '$' &&
		(map[i - 1][j] == '#' || map[i - 1][j] == '0'))
		map[i - 1][j] = ' ';
	ft_space_aux(map, i, j);
}

char		*ft_strdup_map(char *s)
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

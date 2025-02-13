/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 15:23:34 by fernando          #+#    #+#             */
/*   Updated: 2020/08/27 11:30:22 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_resolution(char *s, t_info *info_map)
{
	int i;

	i = 1;
	while (s[i] == ' ')
		i++;
	info_map->rx = ft_atoi(&s[i]);
	if (!ft_strchr(&s[i], ' '))
		return (0);
	while (s[i] != ' ')
		i++;
	info_map->ry = ft_atoi(&s[i]);
	while (s[++i] != '\0')
	{
		if (s[i] == ' ')
			i++;
		else if (!ft_isdigit(s[i]))
			return (0);
	}
	if (info_map->rx <= 0 && info_map->ry <= 0)
		return (0);
	return (1);
}

int		ft_get_texture_path_north_south(char *s, t_info *info_map)
{
	int	i;

	i = 2;
	while (s[i] == ' ')
		i++;
	if (s[0] == 'N' && s[1] == 'O')
	{
		if (info_map->north_t[0] != '\0')
			return (ft_management_error(11, s));
		ft_strcpy(info_map->north_t, &s[i]);
	}
	else if (s[0] == 'S' && s[1] == 'O')
	{
		if (info_map->south_t[0] != '\0')
			return (ft_management_error(11, s));
		ft_strcpy(info_map->south_t, &s[i]);
	}
	return (1);
}

int		ft_convert_rgb_to_integer(char *s)
{
	int		i;
	int		nb[4];
	char	**tab;

	i = 0;
	tab = ft_split(&s[1], ',');
	while (tab[i])
		i++;
	if (i > 3)
		return (ft_management_error(4, s));
	i = 0;
	while (i < 3)
	{
		if ((tab[i] == NULL) || !ft_check_space_rgb(tab, i))
			return (ft_management_error(4, s));
		else
		{
			nb[i] = ft_atoi(tab[i]);
			i++;
		}
	}
	ft_free_tab(tab);
	nb[i] = ft_verif_rgb_is_valid(nb, i);
	return (nb[i]);
}

int		ft_get_color(char *s, t_info *info_map)
{
	int i;

	i = 1;
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == ',')
			i++;
		else if (!ft_isdigit(s[i]))
			return (ft_management_error(3, s));
	}
	if (s[0] == 'F' && info_map->colorf == 0)
		info_map->colorf = ft_convert_rgb_to_integer(s);
	else if (s[0] == 'C' && info_map->colorc == 0)
		info_map->colorc = ft_convert_rgb_to_integer(s);
	else
	{
		ft_putstr_fd("Error\nDuplicate color floor or ceil :", 1);
		return (ft_management_error(9, s));
	}
	if (info_map->colorf == -1 || info_map->colorc == -1)
		return (0);
	return (1);
}

int		ft_get_info_map(char *s, t_info *info_map)
{
	if (s[0] == 'R')
		return (ft_get_info_map_resolution(s, info_map));
	else if ((s[0] == 'N' && s[1] == 'O') || (s[0] == 'S' && s[1] == 'O'))
	{
		if ((ft_get_texture_path_north_south(s, info_map)) == 0)
			return (0);
	}
	else if (((s[0] == 'W' && s[1] == 'E') || (s[0] == 'E' && s[1] == 'A')) ||
		s[0] == 'S')
	{
		if ((ft_get_texture_path_west_east_s(s, info_map)) == 0)
			return (0);
	}
	else if ((s[0] == 'F' || s[0] == 'C') && s[1] == ' ')
	{
		if ((ft_get_color(s, info_map)) == 0)
			return (0);
	}
	else if (s[0] == '\n' || s[0] == '\0')
		return (1);
	else
		return (ft_management_error(3, s));
	return (1);
}

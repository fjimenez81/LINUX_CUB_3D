/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 18:17:36 by fernando          #+#    #+#             */
/*   Updated: 2020/08/20 13:40:42 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	ft_map_aux(char *s, int i, int bool)
{
	if ((s[i] != ' ' && s[i] != '1') && s[i + 1] == ' ' && bool)
		s[i + 1] = '0';
	if (s[i] == '2' && s[i - 1] == '0' && s[i + 2] == '1' && bool)
	{
		s[i] = '0';
		s[i + 1] = '2';
	}
	if (s[i] == ' ' && s[i - 1] == '1' && s[i + 1] == '2' && bool)
	{
		s[i] = '2';
		s[i + 1] = '0';
	}
	else if (s[i] == ' ' && s[i - 1] == '1' && s[i + 1] == '0' && bool)
		s[i] = '0';
	else if (s[i] == ' ' && s[i - 1] == '1' && s[i + 1] == '1' && bool)
		s[i] = '1';
}
static void		ft_map_space(char *s, int *bool)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if ((s[i] == '1' && s[i - 1] == ' ' && s[i + 1] == ' ' && s[i + 2] == '1') ||
			(s[i] == '1' && s[i + 1] == ' ' && s[i + 2] != '1'))
				*bool = 1;
	}
	
}
char			*ft_strdup_map(char *s)
{
	int		i;
	int		j;
	int		bool;
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	bool = 0;
	ft_map_space(s, &bool);
	i = -1;
	j = 0;
	while (s[++i])
	{
		ft_map_aux(s, i, bool);
		dest[j++] = s[i];
	}
	dest[j] = '\0';
	free(s);
	return (dest);
}

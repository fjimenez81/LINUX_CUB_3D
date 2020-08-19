/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 18:17:36 by fernando          #+#    #+#             */
/*   Updated: 2020/08/19 13:29:36 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	ft_map_aux(char *s, int i)
{
	if ((s[i] != ' ' && s[i] != '1') && s[i + 1] == ' ')
		s[i + 1] = '0';
	if (s[i] == '2' && s[i - 1] == '0' && s[i + 2] == '1')
	{
		s[i] = '0';
		s[i + 1] = '2';
	}
	if (s[i] == ' ' && s[i - 1] == '1' && s[i + 1] == '2')
	{
		s[i] = '2';
		s[i + 1] = '0';
	}
	else if (s[i] == ' ' && s[i - 1] == '1' && s[i + 1] == '0')
		s[i] = '0';
	else if (s[i] == ' ' && s[i - 1] == '1' && s[i + 1] == '1')
		s[i] = '1';
	else if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == ' ' &&
		s[i + 3] == '1')
		s[i + 2] = '0';
}

char			*ft_strdup_map(char *s)
{
	int		i;
	int		j;
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		ft_map_aux(s, i);
		dest[j++] = s[i];
	}
	dest[j] = '\0';
	free(s);
	return (dest);
}

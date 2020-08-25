/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 22:41:37 by fernando          #+#    #+#             */
/*   Updated: 2020/08/25 19:05:02 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_wall(char c)
{
	if (c == '1' || c == ' ' || c == '0' || c == '2')
		return (1);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_point(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 2))))
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i++] = '.';
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int		ft_len_tab(char **args)
{
	int i;

	i = 0;
	while (*args++)
		i++;
	return (i);
}

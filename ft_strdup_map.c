/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 18:17:36 by fernando          #+#    #+#             */
/*   Updated: 2020/08/26 20:57:17 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

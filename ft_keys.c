/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 18:15:27 by fernando          #+#    #+#             */
/*   Updated: 2020/08/19 17:03:06 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_keyrelease(int keycode, t_move *move)
{
	if (keycode == 65307 || keycode == 53)
		move->esc = 0;
	else if (keycode == 119 || keycode == 13)
		move->foward = 0;
	else if (keycode == 115 || keycode == 1)
		move->retreat = 0;
	else if (keycode == 97 || keycode == 0)
		move->left = 0;
	else if (keycode == 100 || keycode == 2)
		move->right = 0;
	else if (keycode == 65361 || keycode == 123)
		move->turn_left = 0;
	else if (keycode == 65363 || keycode == 124)
		move->turn_right = 0;
	else if (keycode == 65505 | keycode == 257)
		move->sprint = 0;
	return (0);
}

int	ft_keypress(int keycode, t_move *move)
{
	if (keycode == 65307 || keycode == 53)
		move->esc = 1;
	else if (keycode == 119 || keycode == 13)
		move->foward = 1;
	else if (keycode == 115 || keycode == 1)
		move->retreat = 1;
	else if (keycode == 97 || keycode == 0)
		move->left = 1;
	else if (keycode == 100 || keycode == 2)
		move->right = 1;
	else if (keycode == 65361 || keycode == 123)
		move->turn_left = 1;
	else if (keycode == 65363 || keycode == 124)
		move->turn_right = 1;
	else if (keycode == 65505 || keycode == 257)
		move->sprint = 1;
	return (0);
}

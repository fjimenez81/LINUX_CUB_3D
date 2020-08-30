/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 18:15:27 by fernando          #+#    #+#             */
/*   Updated: 2020/08/30 20:42:57 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_keyrelease(int keycode, t_move *move)
{
	if (keycode == ESC_KEY)
		move->esc = 0;
	else if (keycode == W_KEY)
		move->foward = 0;
	else if (keycode == S_KEY)
		move->retreat = 0;
	else if (keycode == A_KEY)
		move->left = 0;
	else if (keycode == D_KEY)
		move->right = 0;
	else if (keycode == LEFT_KEY)
		move->turn_left = 0;
	else if (keycode == RIGHT_KEY)
		move->turn_right = 0;
	else if (keycode == LEFT_SHIFT)
		move->sprint = 0;
	return (0);
}

int	ft_keypress(int keycode, t_move *move)
{
	if (keycode == ESC_KEY)
		move->esc = 1;
	else if (keycode == W_KEY)
		move->foward = 1;
	else if (keycode == S_KEY)
		move->retreat = 1;
	else if (keycode == A_KEY)
		move->left = 1;
	else if (keycode == D_KEY)
		move->right = 1;
	else if (keycode == LEFT_KEY)
		move->turn_left = 1;
	else if (keycode == RIGHT_KEY)
		move->turn_right = 1;
	else if (keycode == LEFT_SHIFT)
		move->sprint = 1;
	return (0);
}

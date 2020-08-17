/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 18:15:27 by fernando          #+#    #+#             */
/*   Updated: 2020/08/17 16:26:42 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					ft_keyrelease(int keycode, t_move *move)
{
	if (keycode == 65307)
		move->esc = 0;
	else if (keycode == 119)
		move->foward = 0;
	else if (keycode == 115)
		move->retreat = 0;
	else if (keycode == 97)
		move->left = 0;
	else if (keycode == 100)
		move->right = 0;
	else if (keycode == 65361)
		move->turn_left = 0;
	else if (keycode == 65363)
		move->turn_right = 0;
	else if (keycode == 65505)
		move->sprint = 0;
	return (0);
}

int					ft_keypress(int keycode, t_move *move)
{
	if (keycode == 65307)
		move->esc = 1;
	else if (keycode == 119)
		move->foward = 1;
	else if (keycode == 115)
		move->retreat = 1;
	else if (keycode == 97)
		move->left = 1;
	else if (keycode == 100)
		move->right = 1;
	else if (keycode == 65361)
		move->turn_left = 1;
	else if (keycode == 65363)
		move->turn_right = 1;
	else if (keycode == 65505)
		move->sprint = 1;
	return (0);
}

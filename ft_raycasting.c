/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:48:15 by fernando          #+#    #+#             */
/*   Updated: 2020/08/17 16:34:47 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calcul_step_init_sidedist(t_ray *ray, t_storage *storage)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (storage->player->pos_x - ray->map_x)
		* ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - storage->player->pos_x)
		* ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (storage->player->pos_y - ray->map_y)
		* ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - storage->player->pos_y)
		* ray->deltadist_y;
	}
}

void	ft_ddaalgo(t_ray *ray, t_storage *storage, int x)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (storage->info->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - storage->player->pos_x +
		(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - storage->player->pos_y +
		(1 - ray->step_y) / 2) / ray->raydir_y;
	storage->zbuffer[x] = ray->perpwalldist;
}

void	ft_raycaster(t_storage *storage, t_ray *ray)
{
	int		x;

	x = 0;
	storage->zbuffer = malloc(sizeof(double) * storage->info->rx);
	while (x < storage->info->rx)
	{
		ray->cam_x = 2 * x / (double)storage->info->rx - 1;
		ray->raydir_x = storage->player->dir_x + ray->plane_x * ray->cam_x;
		ray->raydir_y = storage->player->dir_y + ray->plane_y * ray->cam_x;
		ray->map_x = (int)storage->player->pos_x;
		ray->map_y = (int)storage->player->pos_y;
		ray->deltadist_x = fabs(1 / ray->raydir_x);
		ray->deltadist_y = fabs(1 / ray->raydir_y);
		ft_calcul_step_init_sidedist(ray, storage);
		ft_ddaalgo(ray, storage, x);
		ft_management_texture(storage, ray, x);
		ray->hit = 0;
		x++;
	}
}

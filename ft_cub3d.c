/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:44:28 by fernando          #+#    #+#             */
/*   Updated: 2020/08/30 21:06:15 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_expose(t_storage *s)
{
	int		i;

	i = 0;
	s->mlx->img = mlx_new_image(s->mlx->ptr, s->info->rx, s->info->ry);
	s->mlx->data_img = mlx_get_data_addr(s->mlx->img, &s->mlx->bpixel,
	&s->mlx->size_line, &s->mlx->endian);
	s->mlx->bpixel = s->mlx->bpixel / 8;
	while (i < s->info->rx * (s->info->ry / 2))
		*(int *)&s->mlx->data_img[i++ * s->mlx->bpixel] = s->info->colorc;
	while (i < s->info->rx * (s->info->ry))
		*(int *)&s->mlx->data_img[i++ * s->mlx->bpixel] = s->info->colorf;
	ft_raycaster(s, s->ray);
	ft_management_sprite(s, s->sprite, s->info->sprite_nb);
	free(s->zbuffer);
	ft_player_pos_cam(s, s->player);
	mlx_put_image_to_window(s->mlx->ptr, s->mlx->win, s->mlx->img, 0, 0);
	if (s->save == 0)
		mlx_destroy_image(s->mlx->ptr, s->mlx->img);
	if (s->move->esc == 1)
		ft_exit_prog(s);
	return (0);
}

int		ft_management_program(t_info *map, t_mlx *mlx)
{
	t_move		move;
	t_player	player;
	t_ray		ray;
	t_storage	storage;
	t_texture	texture[6];

	ft_get_pos_sprite(map, &storage);
	ft_init_struct_move(&move);
	ft_init_struct_player(&player);
	ft_init_struct_ray(&ray);
	ft_fill_storage(&move, &ray, &storage);
	ft_init_storage(map, mlx, &player, &storage);
	ft_init_pos_player(&storage, &player);
	if ((mlx->ptr = mlx_init()) == NULL)
		return (ft_management_error(9, "Error: init fail"));
	if (!(mlx->win = mlx_new_window(mlx->ptr, map->rx, map->ry, "Cub3d")))
		return (ft_management_error(9, "Error: windows fail"));
	if ((ft_init_texture(&storage, texture, 64, 64) == 0))
		return (0);
	mlx_hook(mlx->win, 2, 1, ft_keypress, &move);
	mlx_hook(mlx->win, 3, 2, ft_keyrelease, &move);
	mlx_hook(mlx->win, X_BTN, 0, ft_exit_prog, &storage);
	mlx_loop_hook(mlx->ptr, ft_expose, &storage);
	mlx_loop(mlx->ptr);
	return (0);
}

int		ft_init_program(int save, char **av, t_mlx mlx)
{
	t_info	info_map;

	ft_init_struct_infomap(&info_map);
	if (!ft_read_management(av[1], &info_map))
		return (0);
	ft_check_len_map(&info_map);
	ft_valid_map(&info_map, info_map.player_y, info_map.player_x);
	ft_get_sprite_nb(&info_map);
	if (save == 1)
		ft_save(&info_map, &mlx);
	else
		ft_management_program(&info_map, &mlx);
	return (0);
}

int		main(int ac, char **av)
{
	int		save;
	t_mlx	mlx;

	save = 0;
	mlx.ptr = 0;
	if (ac < 2)
		ft_management_error(-1, "");
	else if (ac > 3)
		ft_management_error(0, "");
	else if (ac == 3)
	{
		if ((ft_strncmp(av[2], "--save", 7) != 0))
			return (ft_management_error(-2, ""));
		else
			save = 1;
	}
	if (ac == 2 || (ac == 3 && save == 1))
		ft_init_program(save, av, mlx);
	return (0);
}

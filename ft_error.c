/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:56:53 by fernando          #+#    #+#             */
/*   Updated: 2020/08/27 10:37:52 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_information_start(int error)
{
	if (error == -1)
		ft_putstr_fd("Error\nfile not finish .cub\n", 1);
	else if (error == 0)
	{
		ft_putstr_fd("Error\nToo much argument, run only with", 1);
		ft_putstr_fd(" file [*.cub] and option --save\n", 1);
	}
	else if (error == 1)
	{
		ft_putstr_fd("Error\nExtension of files no correct, put format", 1);
		ft_putstr_fd(" [*.cub]\n", 1);
	}
	else if (error == 2)
		ft_putstr_fd("Error\nopen(*.cub) failed\n", 1);
	else if (error == -2)
	{
		ft_putstr_fd("Error\nthird argument no correct", 1);
		ft_putstr_fd("only option --save\n", 1);
	}
}

void	ft_information_error(int error, char *s)
{
	if (error == 3)
	{
		ft_putstr_fd("Error\ninformation no correct [", 1);
		ft_putstr_fd(s, 1);
		ft_putstr_fd("]\n", 1);
	}
	else if (error == 4)
	{
		ft_putstr_fd("Error\ncolor for floor or ceil not correct [", 1);
		ft_putstr_fd(s, 1);
		ft_putstr_fd("]\nExemple : F 220,100,0\n", 1);
	}
	else if (error == 10)
		ft_putstr_fd("Error\nBad resolution\n", 1);
	else if (error == 11)
	{
		ft_putstr_fd("Error\nDuplicate texture [", 1);
		ft_putstr_fd(s, 1);
		ft_putstr_fd("]\n", 1);
	}
}

void	ft_map_error(int error)
{
	if (error == 5)
	{
		ft_putstr_fd("Error\nMap no valid, ", 1);
		ft_putstr_fd("the map isn't surrounded by a wall\n", 1);
	}
	else if (error == 6)
	{
		ft_putstr_fd("Error\nCharacter in the map no valid, ", 1);
		ft_putstr_fd("put only [0,1,2,N,S,E,W]\n", 1);
	}
	else if (error == 7)
		ft_putstr_fd("Error\nMultiple player positions\n", 1);
	else if (error == 8)
		ft_putstr_fd("Error\nNo player positions\n", 1);
}

int		ft_management_error(int error, char *s)
{
	if (error >= -2 && error <= 2)
		ft_information_start(error);
	if (error == 3 || error == 4 || error == 10 || error == 11)
		ft_information_error(error, s);
	if (error >= 5 && error <= 8)
		ft_map_error(error);
	if (error == 9)
		ft_putstr_fd(s, 1);
	if (error == 4)
		return (-1);
	return (0);
}

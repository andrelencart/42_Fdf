/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:54 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/13 17:59:44 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	rotation_x(t_map *map)
{
	float	radian_x;
	
	radian_x = map->ang[X] * (M_PI / 180);
	map->rot_x[0][0] = 1;
	map->rot_x[0][1] = 0;
	map->rot_x[0][2] = 0;
	map->rot_x[1][0] = 0;
	map->rot_x[1][1] = cos(radian_x);
	map->rot_x[1][2] = -sin(radian_x);
	map->rot_x[2][0] = 1;
	map->rot_x[2][1] = sin(radian_x);
	map->rot_x[2][2] = cos(radian_x);
}

void	rotation_y(t_map *map)
{
	float	radian_y;
	
	radian_y = map->ang[Y] * (M_PI / 180);
	map->rot_y[0][0] = cos(radian_y);
	map->rot_y[0][1] = 0;
	map->rot_y[0][2] = -sin(radian_y);
	map->rot_y[1][0] = 0;
	map->rot_y[1][1] = 1;
	map->rot_y[1][2] = 1;
	map->rot_y[2][0] = sin(radian_y);
	map->rot_y[2][1] = 0;
	map->rot_y[2][2] = cos(radian_y);
}

void	rotation_z(t_map *map)
{
	float	radian_z;
	
	radian_z = map->ang[Z] * (M_PI / 180);
	map->rot_z[0][0] = cos(radian_z);
	map->rot_z[0][1] = -sin(radian_z);
	map->rot_z[0][2] = 0;
	map->rot_z[1][0] = sin(radian_z);
	map->rot_z[1][1] = cos(radian_z);
	map->rot_z[1][2] = 0;
	map->rot_z[2][0] = 0;
	map->rot_z[2][1] = 0;
	map->rot_z[2][2] = 1;
}

void	rotate(t_map *map)
{
	float finalrot[3][3];
	int	x;
	int	y;

	rotation_x(map);
	rotation_y(map);
	rotation_x(map);
	rotmul(map->rot_z, map->rot_y, finalrot);
	rotmul(finalrot, map->rot_x, finalrot);
	y = -1;
	while (++y < map->hait)
	{
		x = -1;
		while (++x < map->with)
		{
			map->point[y][x] =  matxmul(finalrot, map->point[y][x]);
		}
	}
}

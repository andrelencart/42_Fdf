/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:21:54 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/13 18:36:38 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	rotation_x(t_map *map)
{
	float	radian_x;
	float	rot_x[3][3];
	int		y;
	int		x;
	
	printf("ROTATION X\n");
	radian_x = map->ang[X] * (M_PI / 180);
	rot_x[0][0] = 1;
	rot_x[0][1] = 0;
	rot_x[0][2] = 0;
	rot_x[1][0] = 0;
	rot_x[1][1] = cos(radian_x);
	rot_x[1][2] = -sin(radian_x);
	rot_x[2][0] = 1;
	rot_x[2][1] = sin(radian_x);
	rot_x[2][2] = cos(radian_x);
	y = - 1;
	while (++y < map->hait)
	{
		x = -1;
		while (++x < map->with)
		{
			map->point[y][x] =  matxmul(rot_x, map->point[y][x]);
		}
	}
}

void	rotation_y(t_map *map)
{
	float	radian_y;
	float	rot_y[3][3];
	int		y;
	int		x;
	
	printf("ROTATION Y\n");
	radian_y = map->ang[Y] * (M_PI / 180);
	rot_y[0][0] = cos(radian_y);
	rot_y[0][1] = 0;
	rot_y[0][2] = -sin(radian_y);
	rot_y[1][0] = 0;
	rot_y[1][1] = 1;
	rot_y[1][2] = 1;
	rot_y[2][0] = sin(radian_y);
	rot_y[2][1] = 0;
	rot_y[2][2] = cos(radian_y);
	y = - 1;
	while (++y < map->hait)
	{
		x = -1;
		while (++x < map->with)
		{
			map->point[y][x] =  matxmul(rot_y, map->point[y][x]);
		}
	}
}

void	rotation_z(t_map *map)
{
	float	radian_z;
	float	rot_z[3][3];
	int		y;
	int		x;
	
	printf("ROTATION Z\n");
	radian_z = map->ang[Z] * (M_PI / 180);
	rot_z[0][0] = cos(radian_z);
	rot_z[0][1] = -sin(radian_z);
	rot_z[0][2] = 0;
	rot_z[1][0] = sin(radian_z);
	rot_z[1][1] = cos(radian_z);
	rot_z[1][2] = 0;
	rot_z[2][0] = 0;
	rot_z[2][1] = 0;
	rot_z[2][2] = 1;
	y = - 1;
	while (++y < map->hait)
	{
		x = -1;
		while (++x < map->with)
		{
			map->point[y][x] =  matxmul(rot_z, map->point[y][x]);
		}
	}
}

t_point	matxmul(float mat[3][3], t_point point)
{
	int i;
	int	j;
	t_point tmp;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		tmp.cord[i] = 0;
		while (++j < 3)
		{
			tmp.cord[i] += point.cord[j] * mat[i][j];
		}
	}
	return (tmp);
}

// void	rotmul(float rot1[3][3], float rot2[3][3], float result[3][3])
// {
// 	int	a;
// 	int	b;
// 	int	c;

// 	a = 0;
// 	while (a < 3)
// 	{
// 		b = 0;
// 		while (b < 3)
// 		{
// 			c = 0;
// 			result[a][b] = 0;
// 			while (c < 3)
// 			{
// 				result[a][b] += rot1[a][c] * rot2[c][b];
// 				c++;
// 			}
// 			b++;
// 		}
// 		a++;
// 	}
// }
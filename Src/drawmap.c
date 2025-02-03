/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:04:07 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/03 15:13:48 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	dda_alg(t_map *map)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < map->hait)
	{
		x = 0;
		while (x < map->with)
		{
			if(x != map->with - 1)
				map->point.dx = abs_v(map->point.cord[y][x + 1] - map->point.cord[y][x]);				
			if(y != map->hait - 1)
				map->point.dy = abs_v(map->point.cord[y + 1][x] - map->point.cord[y][x]);
			// ft_printf("dx: %d, dy: %d\n", (int)map->point.dx, (int)map->point.dy);
			dda_steps(map);
			x++;
		}
		map->point.cord[y][x] = 0;
		y++;
	}
	map->point.cord[y] = NULL;
	free_cord(map);
}

void	dda_steps(t_map *map)
{
	float step;

	step = 0;
	if (map->point.dx <= map->point.dy)
		step = map->point.dx;
	else
		step = map->point.dy;
}

void	put_line(t_window *wind)
{
	int	y;
	int	j;

	y = 0;
	j = 400;
	while (y < j)
	{
		my_mlx_pixel_put(wind, 300, y, 0x00FFFFFF);
		y++;
	}
	mlx_put_image_to_window(wind->mlx, wind->mlx_window, wind->img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:04:07 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/30 21:35:51 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

// void	draw_map(t_map *map)
// {
// 	map_delta(map);
// }

void	map_delta(t_map *map)
{
	int	y;
	int	x;
	
	y = 0;
	while (map->point.cord[y])
	{
		x = 0;
		while (map->point.cord[y][x])
		{
			printf("x: %f\n", map->point.cord[y][x]);
			if(x + 1 == '\0' || y + 1 == '\0')
				return ;
			map->point.dx = abs_v(map->point.cord[y][x + 1] - map->point.cord[y][x]);
			map->point.dy = abs_v(map->point.cord[y + 1][x] - map->point.cord[y][x]);
			printf("dx: %f\n", map->point.dx);
			printf("dy: %f\n", map->point.dy);
			x++;
		}
		y++;
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:04:07 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/30 17:49:16 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"


void	map_delta(t_map *map)
{
	int	y;
	int	x;
	
	y = 0;
	while (map->point.cord)
	{
		x = 0;
		while (map->point.cord[y])
		{

		}
	}
}

void	draw_map(t_map *map)
{
	map_delta(map);
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

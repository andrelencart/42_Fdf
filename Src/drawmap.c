/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:04:07 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/13 18:06:24 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	draw_map(t_map *map, t_window *img)
{
	// rotate(map);
	dda_alg(map, img);
}
void	dda_alg(t_map *map, t_window *img)
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
				dda_steps(map, img, map->point[y][x], map->point[y][x + 1]);
			if(y != map->hait - 1)
				dda_steps(map, img, map->point[y][x], map->point[y + 1][x]);
			//printf("x: %f y: %f z: %f dx: %f dy: %f\n\n", x, y, (int)map->point[y][x].cord[Z], (int)map->point[y][x].dx, (int)map->point[y][x].dy);
			x += 1;
		
		}
		y += 1;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->img, 0, 0);
	free_cord(map);
}

void	dda_steps(t_map *map, t_window *img, t_point cord1, t_point cord2)
{
	float	step;
	float	xin;
	float	yin;
	
	map->point[Y][X].dx = (cord2.cord[X] * map->scale) - (cord1.cord[X] * map->scale);
	map->point[Y][X].dy = (cord2.cord[Y] * map->scale) - (cord1.cord[Y] * map->scale);
	step = sqrt(pow(map->point[Y][X].dx , 2) + pow(map->point[Y][X].dy, 2));
	printf("dx: %f dy: %f\n", map->point[Y][X].dx, map->point[Y][X].dy);
	xin = map->point[Y][X].dx / step;
	yin = map->point[Y][X].dy / step;
	cord1.dx = map->orig_cord[X] + (cord1.cord[X] * map->scale);
	cord1.dy = map->orig_cord[Y] + (cord1.cord[Y] * map->scale);
	printf("steps %f\n", step);
	while (step >= 0)
	{
		printf("x -> %d, y-> %d\n", (int)cord1.dx, (int)cord1.dy);
		my_mlx_pixel_put(img, (int)cord1.dx, (int)cord1.dy, WHITE);
		cord1.dx += xin;
		cord1.dy += yin;
		step--;
	}
}

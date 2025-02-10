/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:06:58 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/10 19:13:33 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	window_init(t_window *wind)
{
	wind->mlx = mlx_init();
	wind->mlx_window = mlx_new_window(wind->mlx, WIDTH, \
		HEIGHT, "Fdf by Andcarva");
	wind->img = mlx_new_image(wind->mlx, WIDTH, HEIGHT);
	wind->addr = mlx_get_data_addr(wind->img, &wind->bitpp, \
		&wind->line_length, &wind->endian);
}

void	map_init(t_map *map, char *file)
{
	map_format(file);
	map->hait = 0;
	map->with = 0;
	map->orig_cord[X] = WIDTH / 2;
	map->orig_cord[Y] = HEIGHT / 2;
	map->orig_cord[Z] = 0;
	map->scale = 25;
	map_info(map, file);
	map_matriz(map, file);
}

void	parser(t_map *map, char *file)
{
	error_extension(file);
	map_init(map, file);
}

// void	point_init(t_map *map, int with, int hait)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	printf("Width -> %d, Height -> %d\n", with, hait);
// 	while (y < hait)
// 	{
// 		x = 0;
// 		while (x < with)
// 		{	
// 			map->point[y][x].cord[X] = 0;
// 			map->point[y][x].cord[Y] = 0;
// 			map->point[y][x].cord[Z] = 0;
// 			map->point[y][x].dx = 0;
// 			map->point[y][x].dy = 0;
// 			map->point[y][x].color = WHITE;
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	line_memory(t_point **points, int with, int hait)
{
	int	y;

	y = 0;
	while (y < hait)
	{		
		points[y] = malloc(sizeof(t_point) * (with));
		if (!points[y])
			ft_error("Cord not initialized!", 0);
		y++;
	}
}
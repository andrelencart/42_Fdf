/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:06:58 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/19 17:05:25 by andcarva         ###   ########.fr       */
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
	float	scalex;
	float	scaley;
	
	map->file = file;
	map_format(file);
	map->hait = 0;
	map->with = 0;
	map->orig_cord[X] = WIDTH / 2;
	map->orig_cord[Y] = HEIGHT / 2;
	map->orig_cord[Z] = 0;
	map_info(map, file);
	scalex = (float)WIDTH / (map->with + 1);
	scaley = (float)HEIGHT / (map->hait + 1);
	if (scalex < scaley)
		map->scale = scalex;
	else
		map->scale = scaley;
	map_matriz(map, file);
}

void	parser(t_map *map, char *file)
{
	error_extension(file);
	map_init(map, file);
	isometric(map);
}


void	line_memory(t_point **points, int with, int hait)
{
	int	y;

	y = 0;
	while (y < hait)
	{		
		points[y] = malloc(sizeof(t_point) * (with));
		if (!points[y])
			ft_error(ERROR_ARGS, 0);
		y++;
	}
}

// void	restart_map(t_map *map)
// {
// 	float	scalex;
// 	float	scaley;
	
// 	map->hait = 0;
// 	map->with = 0;
// 	map->orig_cord[X] = WIDTH / 2;
// 	map->orig_cord[Y] = HEIGHT / 2;
// 	map->orig_cord[Z] = 0;
// 	map_info(map, map->file);
// 	scalex = (float)WIDTH / (map->with + 1);
// 	scaley = (float)HEIGHT / (map->hait + 1);
// 	if (scalex < scaley)
// 		map->scale = scalex;
// 	else
// 		map->scale = scaley;
// }

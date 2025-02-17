/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:06:58 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/17 19:05:49 by andcarva         ###   ########.fr       */
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
	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 45;
	map->scale = 20;
	map_info(map, file);
	map_matriz(map, file);
}

void	parser(t_map *map, char *file)
{
	error_extension(file);
	map_init(map, file);
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
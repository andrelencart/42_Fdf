/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:06:58 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/30 17:35:36 by andcarva         ###   ########.fr       */
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
	// printf("mlx = %p\n", wind->mlx);
	// printf("window = %p\n", wind->mlx_window);
	// printf("img = %p\n", wind->img);
	// printf("addr = %p\n", wind->addr);
}

void	map_init(t_map *map, char *file)
{
	map->hait = 0;
	map->with = 0;
	map_info(map, file);
	map->point.cord = malloc(sizeof(float *) * (map->hait + 1));
	if (!map->point.cord)
		perror("Cord not initialized!");
	map_matriz(map, file);
}

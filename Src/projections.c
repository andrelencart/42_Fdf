/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:43:01 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/19 20:48:36 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	isometric(t_map *map)
{
	// printf("isometric\n");
	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 45;
}

void	top_v(t_map *map)
{
	// printf("top_v\n");
	map->ang[X] = 0;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
}

void	side_v(t_map *map)
{
	// printf("side_v\n");
	map->ang[X] = 90;
	map->ang[Y] = 90;
	map->ang[Z] = 0;
}

void	front_v(t_map *map)
{
	// printf("front_v\n");
	map->ang[X] = 90;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
}

void	projection_choice(t_map *map, int proj)
{
	// map_init(map, map->file);
	if (proj == ISOMETRIC)
		isometric(map);
	else if (proj == TOP_VIEW)
		top_v(map);
	else if (proj == SIDE_VIEW)
		side_v(map);
	else if (proj == FRONT_VIEW)
		front_v(map);
	// rotation_x(map);
	// rotation_y(map);
	// rotation_z(map); 
}
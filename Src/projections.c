/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:43:01 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/11 18:19:49 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	rotations()
{
	
}

void	isometric(t_map *map)
{
	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 45;
}

void	top_view(t_map *map)
{
	map->ang[X] = 0;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
}
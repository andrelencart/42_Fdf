/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:07:33 by andcarva          #+#    #+#             */
/*   Updated: 2025/07/15 13:05:29 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	hook_control(t_fdf *fdf)
{
	mlx_hook(fdf->window.mlx_window, 17, 0, window_close, fdf);
	mlx_key_hook(fdf->window.mlx_window, testkey, fdf);
	mlx_hook(fdf->window.mlx_window, 2, 1L << 0, key_press, fdf);
	mlx_mouse_hook(fdf->window.mlx_window, map_zoom, fdf);
}

int	key_press(int key_code, t_fdf *fdf)
{
	
	if (key_code == ESC)
		window_close(&fdf->window);
	else if (key_code == KB1 || key_code == KB2 \
		|| key_code == KB3 || key_code == KB4)
		key_projection_change(key_code, fdf);
	else if (key_code == UP || key_code == DOWN \
		|| key_code == RA || key_code == LA)
		translation(key_code, fdf);
	else if (key_code == W || key_code == S \
		|| key_code == A || key_code == D)
		rotate_map(key_code, fdf);
	else if (key_code == P || key_code == M)
		update_z_scale(key_code, &fdf->map);
	else if (key_code == R)
	{

		map_init(&fdf->map, fdf->map.file);
		isometric(&fdf->map);
        draw_map(&fdf->map, &fdf->window);
	}
	return (0);
}

int	key_projection_change(int key_code, t_fdf *fdf)
{
	if (key_code == KB1)
		projection_choice(&fdf->map, ISOMETRIC);
	else if (key_code == KB2)
		projection_choice(&fdf->map, TOP_VIEW);
	else if (key_code == KB3)
		projection_choice(&fdf->map, SIDE_VIEW);
	else if (key_code == KB4)
		projection_choice(&fdf->map, FRONT_VIEW);
	return (0);
}

int	map_zoom(int key_code, int x, int y, t_fdf *fdf)
{
	float	prev_zoom;

	prev_zoom = fdf->map.zoom;
	if (key_code == SRC_UP)
		fdf->map.zoom *= 1.2;
	else if (key_code == SRC_DOWN && fdf->map.zoom > 0.2)
		fdf->map.zoom /= 1.2;
	else
		return (0);
	fdf->map.orig_cord[X] = x - ((x - fdf->map.orig_cord[X]) \
		* (fdf->map.zoom / prev_zoom));
	fdf->map.orig_cord[Y] = y - ((y - fdf->map.orig_cord[Y]) \
		* (fdf->map.zoom / prev_zoom));
	return (0);
}

void	update_z_scale(int key_code, t_map *map)
{
	if (key_code == P)
		map->z_scale += 1;
	else if (key_code == M)
	{
		if (map->z_scale > 1.0)
			map->z_scale -= 1;
	}
}

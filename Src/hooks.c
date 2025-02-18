/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:07:33 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/18 20:21:27 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	window_close(t_window *wind)
{
	mlx_destroy_image(wind->mlx, wind->img);
	mlx_destroy_window(wind->mlx, wind->mlx_window);
	mlx_destroy_display(wind->mlx);
	free(wind->mlx);
	exit(0);
	return (0);
}

void	hook_control(t_fdf *fdf)
{
	// mlx_key_hook(wind->mlx_window, &testkey, &wind);
	// (void)map;
	mlx_hook(fdf->window.mlx_window, 17, 0, &window_close, fdf);
	mlx_hook(fdf->window.mlx_window, 02, 1L << 0, &key_press, fdf);
}

int	key_press(int key_code, t_fdf *fdf)
{
	if (key_code == ESC)
		window_close(&fdf->window);
	else
		key_projection_change(key_code, fdf);
	return (0);
}

int	key_projection_change(int key_code, t_fdf *fdf)
{
	map_init(&fdf->map, fdf->map.file);
	if (key_code == KB1)
		projection_choice(&fdf->map, ISOMETRIC);
	else if (key_code == KB2)
		projection_choice(&fdf->map, TOP_VIEW);
	else if (key_code == KB3)
		projection_choice(&fdf->map, SIDE_VIEW);
	else if (key_code == KB4)
		projection_choice(&fdf->map, FRONT_VIEW);
	else
		return (0);
	draw_map(&fdf->map, &fdf->window);
	return (0);
}

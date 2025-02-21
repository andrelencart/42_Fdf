/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:07:33 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/21 17:45:13 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	hook_control(t_fdf *fdf)
{
	mlx_key_hook(fdf->window.mlx_window, &testkey, fdf);
	mlx_hook(fdf->window.mlx_window, 17, 0, window_close, fdf);
	mlx_hook(fdf->window.mlx_window, 2, 1L << 0, key_press, fdf);
}

int	key_press(int key_code, t_fdf *fdf)
{
	if (key_code == ESC)
		window_close(&fdf->window, &fdf->map);
	else if (key_code == KB1 || key_code == KB2 \
		|| key_code == KB3 || key_code == KB4)
		key_projection_change(key_code, fdf);
	if (key_code == UP || key_code == DOWN \
		|| key_code == RA || key_code == LA)
		translation(key_code, fdf);
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
		projection_choice(&fdf->map, FRONT_VIEW);;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:07:33 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/30 15:40:26 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	window_close(t_window *wind)
{
	// printf("mlx = %p\n", wind->mlx);
	// printf("window = %p\n", wind->mlx_window);
	// printf("img = %p\n", wind->img);
	// printf("addr = %p\n", wind->addr);
	mlx_destroy_image(wind->mlx, wind->img);
	mlx_destroy_window(wind->mlx, wind->mlx_window);
	mlx_destroy_display(wind->mlx);
	free(wind->mlx);
	exit(0);
	return (0);
}

void	hook_control(t_window *wind)
{
	mlx_key_hook(wind->mlx_window, &testkey, &wind);
	mlx_hook(wind->mlx_window, 17, 0, &window_close, wind);
	mlx_hook(wind->mlx_window, 02, 1L << 0, &key_press, wind);
}

int	key_press(int key_code, t_window *wind)
{
	if (key_code == ESC)
		window_close(wind);
	return (0);
}

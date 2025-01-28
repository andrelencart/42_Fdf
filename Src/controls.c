/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:07:33 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/28 14:40:24 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	window_close(t_window *wind)
{
	// printf("mlx = %p\n", wind->mlx);
	// printf("window = %p\n", wind->mlx_window);
	// printf("img = %p\n", wind->img);
	// printf("addr = %p\n", wind->addr);
	mlx_destroy_window(wind->mlx, wind->mlx_window);
	mlx_destroy_display(wind->mlx);
	free(wind->mlx);
	exit(0);
}
void	hook_control(t_window *wind)
{
	mlx_key_hook(wind->mlx_window, &testkey, &wind);
	mlx_hook(wind->mlx_window, 02, 1L<<0, &key_press, wind);
}
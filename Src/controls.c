/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:07:33 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/21 16:53:34 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	window_close(t_window *wind)
{
	printf("mlx = %p\n", wind->mlx);
	printf("window = %p\n", wind->mlx_window);
	printf("img = %p\n", wind->img);
	printf("addr = %p\n", wind->addr);
	mlx_destroy_window(wind->mlx, wind->mlx_window);
	mlx_destroy_display(wind->mlx);
	free(wind->mlx);
	exit(0);
}
void	hook_control(t_window *wind)
{
	mlx_key_hook(wind->mlx_window, &key_press, wind);
	// mlx_key_hook(wind->mlx_window, &testkey, &wind);
}
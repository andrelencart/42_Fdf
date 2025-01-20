/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:07:33 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/20 20:37:08 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	window_close(t_window *wind)
{
	mlx_destroy_image(wind->mlx, wind->img);
	mlx_destroy_window(wind->mlx, wind->mlx_window);
	free(wind);
	exit(0);
}
void	hook_control(t_window *wind)
{
	mlx_key_hook(wind->mlx_window, &key_press, &wind);
	
}
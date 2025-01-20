/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:31:39 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/20 20:35:13 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(void)
{
	t_window	wind;
	int		y;
	int		j;
	
	y = 0;
	j = 400;
	window_init(&wind);
	while (y < j)
	{
		my_mlx_pixel_put(&wind, 300, y, 0x00FFFFFF);
		y++;
	}
	mlx_put_image_to_window(wind.mlx, wind.mlx_window, wind.img, 0, 0);
	hook_control(&wind);
	mlx_loop(wind.mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.>c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:31:39 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/17 20:24:25 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(void)
{
	t_fdf	fdf;
	// int		x;
	// int		y;
	// int 	i;
	// int		j;
	
	window_init();
	mlx_put_image_to_window(fdf.wind.mlx, fdf.wind.mlx_window, fdf.wind.img, 0, 0);
	window_close(&fdf.wind);
	mlx_loop(&fdf.wind.mlx);
	// x = 960;
	// y = 0;
	// i = 0;
	// j = 1080;
	// while (y < j)
	// {
	// 	my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
	// 		y++;
	// }
	// y = 0;
	// j = 0;
	// x = 0;
	// while (i <= 1080 && j <= 960) 
	// {
	// 	while (x < j)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 		x++;
	// 	}
	// 	while (y < i)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 		y++;
	// 	}
	// 	j += 15;
	// 	i += 16;
	// }
	// printf("%d\n", x);
	// printf("%d\n", y);
	// while (i >= 0  && j <= 1920)
	// {
	// 	while (x < j)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 		x++;
	// 	}
	// 	while (y > i)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 		y--;
	// 	}
	// 	i -= 15;
	// 	j += 16;
	// }
}
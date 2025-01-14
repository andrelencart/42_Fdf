/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:31:39 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/14 18:28:43 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	int		x;
	int		y;
	int 	i;
	int		j;
	
	x = 5;
	y = 5;
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "Windooaaaawwww!!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	i = 0;
	j = 0;
	while (i < 1080 && j < 960) 
	{
		while (x < j)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		while (y < i)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y++;
		}
		j += 9;
		i += 16;
	}
	printf("%d\n", x);
	printf("%d\n", y);
	j = 960;
	while (i > 10  && j < 1920)
	{
		while (x < j)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		while (y > i)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y--;
		}
		i -= 9;
		j += 16;
	}
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
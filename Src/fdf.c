/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:31:39 by andcarva          #+#    #+#             */
/*   Updated: 2025/07/15 13:02:45 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac == 2)
	{
		parser(&fdf.map, av[1]);
		window_init(&fdf.window);
		draw_map(&fdf.map, &fdf.window);
		hook_control(&fdf);
		mlx_loop_hook(fdf.window.mlx, draw_img, &fdf);
		mlx_loop(fdf.window.mlx);
	}
	else
		ft_error(ERROR_ARGS, 0);
}

int	draw_img(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&fdf->window, x, y, BLACK);
			x++;
		}
		y++;
	}
	restart_map(&fdf->map);
	draw_map(&fdf->map, &fdf->window);
	return (0);
}

void	parser(t_map *map, char *file)
{
	error_extension(file);
	map_init(map, file);
	isometric(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:31:39 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/18 21:21:31 by andcarva         ###   ########.fr       */
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
		printf("here\n");
		mlx_loop_hook(fdf.window.mlx, draw_img, &fdf);
		mlx_loop(fdf.window.mlx);
	}
	else
		ft_error(ERROR_ARGS, 0);
}

int	draw_img(t_fdf *fdf)
{
	//printf("pointer img %p\n", &fdf->window.img);
	map_init(&fdf->map, fdf->map.file);
	mlx_destroy_image(fdf->window.mlx, fdf->window.img);
	//printf("pointer img %p\n", &fdf->window.img);
	fdf->window.img = mlx_new_image(fdf->window.mlx, WIDTH, HEIGHT);
	fdf->window.addr = mlx_get_data_addr(fdf->window.img, &fdf->window.bitpp, \
		&fdf->window.line_length, &fdf->window.endian);
	draw_map(&fdf->map, &fdf->window);
	return (0);
}

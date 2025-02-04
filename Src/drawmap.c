/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:04:07 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/04 19:01:18 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	dda_alg(t_map *map, t_window *img)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < map->hait)
	{
		x = 0;
		while (x < map->with)
		{
			if(x != map->with - 1)
				dda_steps(map, img, (t_point){{0}, x, y, WHITE}, (t_point){{0}, x + 1, y, WHITE});
			if(y != map->hait - 1)
				dda_steps(map, img, (t_point){{0}, x, y, WHITE}, (t_point){{0}, x, y + 1, WHITE});
			// ft_printf("x: %d y: %d z: %d dx: %d dy: %d\n", x, y, (int)map->point.cord[y][x], (int)map->point.dx, (int)map->point.dy);
			x += 1;
		}
		map->point[y][x].cord[Z] = 0;
		y += 1;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->img, 0, 0);
	free_cord(map);
}

void	dda_steps(t_map *map, t_window *img, t_point cord1, t_point cord2)
{
	float	step;
	float	xin;
	float	yin;
	int		i;

	map->point.dx = cord2.dx - cord1.dx;
	map->point.dy = cord2.dy - cord1.dy;
	// printf("cord1.x %d cord1.y %d cord2.x %d cord2.y %d\n", (int)cord1.dx, (int)cord1.dy, (int)cord2.dx, (int)cord2.dy);
	if (fabs_v(map->point.dx) >= fabs_v(map->point.dy))
		step = fabs_v(map->point.dx);
	else
		step = fabs_v(map->point.dy);
	if (step == 0)
		step = 1;
	xin = map->point.dx / step;
	yin = map->point.dy / step;
	i = 0;
	while (i <= step)
	{
		my_mlx_pixel_put(img, (int)cord1.dx, (int)cord1.dy, map->point);
		cord1.dx += xin;
		cord1.dy += yin;
		i++;
	}
}

// void	draw_pixel(t_window *wind)
// {
// 	int	y;
// 	int	j;

// 	y = 0;
// 	j = 400;
// 	while (y < j)
// 	{
// 		my_mlx_pixel_put(wind, 300, y, 0x00FFFFFF);
// 		y++;
// 	}
// 	mlx_put_image_to_window(wind->mlx, wind->mlx_window, wind->img, 0, 0);
// }

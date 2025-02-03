/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:04:07 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/03 18:17:08 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	dda_alg(t_map *map, t_window *img, int color)
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
				dda_steps(map, x, y, x + 1, y);
			if(y != map->hait - 1)
				dda_steps(map, x, y, x, y + 1);
			ft_printf("x: %d y: %d z: %d dx: %d dy: %d\n", x, y, (int)map->point.cord[y][x], (int)map->point.dx, (int)map->point.dy);
			x++;
		}
		map->point.cord[y][x] = 0;
		y++;
	}
	free_cord(map);
}

void	dda_steps(t_map *map, int x1, int x2, int y1, int y2)
{
	float	step;
	float	xin;
	float	yin;
	int		i;

	map->point.dx = x2 - x1;
	map->point.dy = y2 - y1;
	if (fabs_v(map->point.dx) >= fabs_v(map->point.dy))
		step = fabs_v(map->point.dx);
	else
		step = fabs_v(map->point.dy);
	if (step == 0)
		step == 1;
	xin = map->point.dx / step;
	yin = map->point.dy / step;
	i = 0;
	while (i <= step)
	{
		my_mlx_pixel_put();
		x1 += xin;
		y1 += yin;
		i++;
	}
}

// void	dda_draw(float xin, float yin, int x1, int y1, float step)
// {
// 	// float	x;
// 	// float	y;
// 	int		i;
// 	// x = x1;
// 	// y = y1;
// 	i = 0;
// 	while (i <= step)
// 	{
// 		my_mlx_pixel_put();
// 		x1 += xin;
// 		y1 += yin;
// 		i++;
// 	}
// }
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

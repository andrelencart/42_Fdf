/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:04:07 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/06 19:33:36 by andcarva         ###   ########.fr       */
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
			ft_printf("map->with: %d\n", map->with);
			if(x != map->with - 1)
				dda_steps(*(map->point), img, (t_point){{0}, x, y, WHITE}, (t_point){{0}, x + 1, y, WHITE});
			if(y != map->hait - 1)
				dda_steps(*(map->point), img, (t_point){{0}, x, y, WHITE}, (t_point){{0}, x, y + 1, WHITE});
			// ft_printf("x: %d y: %d z: %d dx: %d dy: %d\n", x, y, (int)map->point[y][x].cord[Z], (int)map->point[y][x].dx, (int)map->point[y][x].dy);
			x += 1;
		}
		map->point[y][x].cord[Z] = 0;
		y += 1;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->img, 0, 0);
	free_cord(map);
}

void	dda_steps(t_point *point, t_window *img, t_point cord1, t_point cord2)
{
	float	step;
	float	xin;
	float	yin;
	int		i;

	ft_printf("AAAAA\n");
	(*point).dx = cord2.dx - cord1.dx;
	(*point).dy = cord2.dy - cord1.dy;
	// printf("cord1.x %d cord1.y %d cord2.x %d cord2.y %d\n", (int)cord1.dx, (int)cord1.dy, (int)cord2.dx, (int)cord2.dy);
	if (fabs_v((*point).dx) >= fabs_v((*point).dy))
		step = fabs_v((*point).dx);
	else
		step = fabs_v((*point).dy);
	if (step == 0)
		step = 1;
	xin = (*point).dx / step;
	yin = (*point).dy / step;
	i = 0;
	while (i <= step)
	{
		my_mlx_pixel_put(img, (int)cord1.dx, (int)cord1.dy, (*point).color);
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

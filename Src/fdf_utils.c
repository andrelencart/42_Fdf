/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:56:36 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/03 16:35:54 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	my_mlx_pixel_put(t_window *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bitpp / 8));
	*(unsigned int *)dst = color;
}

int	testkey(int key_code, t_window *wind)
{
	(void)wind;
	ft_printf("key_code: %d\n", key_code);
	return (0);
}

float	fabs_v(float n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	free_cord(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->hait)
	{
		free(map->point[y]);
		y++;
	}
	free(map->point);
}

void	ft_error(char *error_msg, int sys_func)
{
	if (!sys_func)
		ft_putendl_fd(error_msg, STDERR_FILENO);
	else
		perror(error_msg);
}

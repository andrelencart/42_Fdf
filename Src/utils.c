/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:56:36 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/17 20:44:08 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	my_mlx_pixel_put(t_window *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bitpp / 8));
	*(unsigned int *)dst = color;
}

// int	key_hook(t_window *wind)
// {
// 	write(1, "Window closed\n", 15);
// 	return (0);
// }

// int	destroy(t_window *wind)
// {
// 	mlx_destroy_window(wind->mlx, wind->mlx_window);
// 	return (0);
// }
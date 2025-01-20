/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:56:36 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/20 20:28:05 by andre            ###   ########.fr       */
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
	printf("key_code: %d\n", key_code);
	return (0);
}
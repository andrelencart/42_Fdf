/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:06:58 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/17 20:48:39 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	window_init(void)
{
	t_window	wind;
	
	wind.mlx = mlx_init();
	wind.mlx_window = mlx_new_window(wind.mlx, 1920, 1080, "|");
	wind.img = mlx_new_image(wind.mlx, 1920, 1080);
	wind.addr = mlx_get_data_addr(wind.img, &wind.bitpp, &wind.line_length, &wind.endian);
}

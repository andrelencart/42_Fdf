/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:31:39 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/28 14:41:15 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(void)
{
	t_fdf	fdf;
	
	window_init(&fdf.window);
	put_line(&fdf.window);
	hook_control(&fdf.window);
	mlx_loop(fdf.window.mlx);
}
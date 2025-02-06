/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:31:39 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/06 15:51:27 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

// need to put the .fdf file as the ones i want;
int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac == 2)
	{
		parser(&fdf.map, av[1]);
		// map_init(&fdf.map, av[1]);
		window_init(&fdf.window);
		dda_alg(&fdf.map, &fdf.window);
		hook_control(&fdf.window);
		mlx_loop(fdf.window.mlx);
	}
	else
		ft_error("To Many Arguments!", 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:07:33 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/17 20:18:44 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"


void	window_close(t_window *wind)
{
	// if (keycode == )
	mlx_hook(wind->mlx_window, 17, 1L<<5, destroy, &wind);
}
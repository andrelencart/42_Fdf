/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:45:38 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/18 17:27:32 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	key_projection_change(int key_code, t_map *map)
{
	if (key_code == KB1)
		projection_choice(map, ISOMETRIC);
	if (key_code == KB2)
		projection_choice(map, TOP_VIEW);
	if (key_code == KB1)
		projection_choice(map, SIDE_VIEW);
	if (key_code == KB1)
		projection_choice(map, FRONT_VIEW);
	return (0);
}

int	key_press(int key_code, t_window *wind)
{
	if (key_code == ESC)
		window_close(wind);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:35:02 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/19 19:19:27 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	translation(int key_code, t_fdf *fdf)
{
	if (key_code == UP)
		fdf->map.orig_cord[Y] -= 100;
	else if (key_code == DOWN)
		fdf->map.orig_cord[Y] += 100;
	else if (key_code == LA)
		fdf->map.orig_cord[X] -= 100;
	else if (key_code == RA)
		fdf->map.orig_cord[X] += 100;
}

void	rotate_map(int key_code, t_fdf *fdf) 
{
	printf("rotations\n");
	if (key_code == W)
	{
		fdf->map.ang[X] -= 5;
		rotation_x(&fdf->map);
	}
	else if (key_code == A)
	{
		fdf->map.ang[Y] -= 5;
		rotation_y(&fdf->map);
	}
	else if (key_code == S)
	{
		fdf->map.ang[X] += 5;
		rotation_x(&fdf->map);
	}
	else if (key_code == D)
	{
		fdf->map.ang[Y] += 5;
		rotation_y(&fdf->map);
	}
}

// void	rotate_map(t_fdf *fdf, int axis, int angle)
// {
// 	printf("rotate map\n");
// 	fdf->map.ang[axis] += angle;

// 	rotation_x(&fdf->map);
// 	rotation_y(&fdf->map);
// }
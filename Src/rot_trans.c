/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:35:02 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/21 17:08:59 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	translation(int	key_code, t_fdf *fdf)
{
	if(key_code == UP)
		fdf->map.orig_cord[Y] -= 100;
	else if(key_code == DOWN)
		fdf->map.orig_cord[Y] += 100;
	else if(key_code == LA)
		fdf->map.orig_cord[X] -= 100;
	else if(key_code == RA)
		fdf->map.orig_cord[X] += 100;
}
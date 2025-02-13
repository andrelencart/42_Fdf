/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:01:55 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/13 15:37:19 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	rotmul(float rot1[3][3], float rot2[3][3], float result[3][3])
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a < 3)
	{
		b = 0;
		while (b < 3)
		{
			c = 0;
			result[a][b] = 0;
			while (c < 3)
			{
				result[a][b] += rot1[a][c] * rot2[c][b];
				c++;
			}
			b++;
		}
		a++;
	}
}


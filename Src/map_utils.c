/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:31:36 by andcarva          #+#    #+#             */
/*   Updated: 2025/07/15 15:46:11 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

static int is_valid(int ch, int base)
{
    char *lwc = "0123456789abcdef";
    char *upc = "0123456789ABCDEF";
    int i = 0;

    while (i < base)
    {
        if (ch == lwc[i] || ch == upc[i])
            return (1);
        i++;
    }
    return (0);
}

int	ft_atoi_base(const char *str, int str_bas)
{
	int	i = 0;
	int res = 0;
	int sign = 1;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
    if (str_bas == 16 && str[i] == '0' && (str[i+1] == 'x' || str[i+1] == 'X'))
        i += 2;
    while (str[i] && is_valid(str[i], str_bas))
    {
        res *= str_bas;
        if (str[i] >= '0' && str[i] <= '9')
            res += str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            res += str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            res += str[i] - 'A' + 10;
        i++;
    }
	return (res * sign);
}
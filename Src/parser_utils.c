/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:23:35 by andre             #+#    #+#             */
/*   Updated: 2025/02/17 16:03:15 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	fd_check(char *file)
{
	int	fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error("ERROR OPENING FILE", 0);
		exit (0);
	}
	if (read(fd, 0, 0) < 0)
	{
		ft_error("ERROR READING FILE", 0);
		close(fd);
		exit (0);
	}
	return (fd);
}

void	error_extension(char *file)
{
	size_t	len;
	
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".fdf", 4) != '\0')
	{
		ft_error("WRONG FILE!", 0);
		exit(1);
	}
}

bool	is_valid_number(char *str)
{
	if (!str)
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str != ' ' && *str != '\t' && *str != '\n')
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

void	free_map(char **map)
{
	int	x;
	
	x = 0;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free(map);
}

void	last_space(char *line, t_map *map)
{
	char	*temp;
	int		i;
	
	temp = line;
	i = -1;
	while (temp[++i])
	{
		if ((temp[i + 1] == ' ' || temp[i + 1] == '\t') && !ft_isdigit(temp[i + 2]))
		{
			ft_error(ERROR_SPACE, 0);
			free(temp);
			free_cord(map);
			exit(0);
		}
	}
}

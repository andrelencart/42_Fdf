/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:23:35 by andre             #+#    #+#             */
/*   Updated: 2025/02/06 19:27:32 by andcarva         ###   ########.fr       */
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

static int	is_retangular(char **map_row, int prev_row, int *fd)
{
	int	x;
	
	x = 0;
	while (map_row[x] && (*map_row[x]) != '\n')
		x++;
	// ft_printf("prev: %d\n", prev_row);
	// ft_printf("x: %d\n", x);
	if (prev_row != -1 && prev_row != x)
	{
		close (*fd);
		ft_error("MAP NOT RETANGULAR!", 0);
		free_map(map_row);
		exit (0);
	}
	if (prev_row != -1)
		return prev_row;
	return (x);
}

void	map_format(char *file)
{
	char	**map_row;
	char	*line;
	char	*temp;
	int		fd;
	int		prev_row;

	fd = fd_check(file);
	prev_row = -1;
	line = get_next_line(fd);
	while (line)
	{
		temp = line;
		map_row = ft_split(temp, ' ');
		free(temp);
		if (!map_row)
			return ;
		prev_row = is_retangular(map_row, prev_row, &fd);
		line = get_next_line(fd);
		free_map(map_row);
	}
	close (fd);
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

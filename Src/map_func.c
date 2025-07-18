/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:54 by andcarva          #+#    #+#             */
/*   Updated: 2025/07/15 19:12:51 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	map_info(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = fd_check(file);
	line = get_next_line(fd);
	if (!line)
		ft_error(ERROR_MAP, 0);
	map->mtz = ft_split(line, ' ');
	while (line)
	{
		map->hait++;
		free(line);
		line = get_next_line(fd);
	}
	while (map->mtz[map->with])
	{
		free(map->mtz[map->with]);
		map->with++;
	}
	free(map->mtz);
	close(fd);
}

static void	map_cord_put(char *line, int y, t_map *map)
{
	int		x;
	char	**cells;
	char	*cell;
	char	*comma;
	
	cells = ft_split(line, ' ');
	if (!cells)
	{
		ft_error(ERROR_INIT, 0);
		exit(1);
	}
	x = 0;
	while (x < map->with)
	{
		cell = cells[x];
		comma = ft_strchr(cell, ',');
		if (comma)
		{
			*comma = '\0';
			map->point[y][x].cord[Z] = ft_atoi(cell) * map->z_scale;
			char *color_str = comma + 1;
			map->point[y][x].color = ft_atoi_base(color_str, 16);
			*comma = ',';
		}
		else
		{
			map->point[y][x].cord[Z] = ft_atoi(cell) * map->z_scale;
			map->point[y][x].color = WHITE;
		}
		map->point[y][x].cord[X] = (x + 0.5 - (map->with / 2));
		map->point[y][x].cord[Y] = (y + 0.5 - (map->hait / 2));
		x++;
	}
	free_map(cells);
}

void	map_matriz(t_map *map, char *file)
{
	int		fd;
	int		y;
	char	*temp;
	char	*line;

	y = 0;
	fd = fd_check(file);
	map->point = malloc(sizeof(t_point *) * (map->hait));
	if (!map->point)
		ft_error(ERROR_INIT, 0);
	line_memory(map->point, map->with, map->hait, map);
	while (y < map->hait)
	{
		line = get_next_line(fd);
		temp = line;
		map_cord_put(temp, y, map);
		free(line);
		y++;
	}
	close (fd);
}

// static int	is_retangular(char **map_row, int prev_row, int *fd)
// {
// 	int	x;

// 	x = 0;
// 	while (map_row[x] && (*map_row[x]) != '\n')
// 		x++;
// 	if (prev_row != -1 && prev_row != x)
// 	{
// 		close (*fd);
// 		ft_error(ERROR_FORMAT, 0);
// 		free_map(map_row);
// 		exit (0);
// 	}
// 	if (prev_row != -1)
// 		return (prev_row);
// 	return (x);
// }

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
		// prev_row = is_retangular(map_row, prev_row, &fd);
		line = get_next_line(fd);
		free_map(map_row);
	}
	close (fd);
}

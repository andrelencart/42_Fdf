/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:54 by andcarva          #+#    #+#             */
/*   Updated: 2025/07/15 17:30:45 by andcarva         ###   ########.fr       */
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

// static void	map_cord_put(char *line, int y, t_map *map)
// {
// 	int		x;
// 	char	*temp;
// 	char 	*comma;
// 	char 	*color_str;

// 	x = 0;
// 	temp = line;
// 	while (*temp && x < map->with)
// 	{
// 		while (*temp == ' ' || *temp == 9)
// 			temp++;
// 		comma = ft_strchr(temp, ',');
// 		printf("coma: %s\n", comma);
// 		if (comma)
// 		{
// 			*comma = '\0';
// 			map->point[y][x].cord[Z] = ft_atoi(temp) * map->z_scale;
// 			color_str = comma + 2;
// 			map->point[y][x].color = ft_atoi_base(color_str, 16);
// 			printf("color: %X\n", map->point[y][x].color);
// 			*comma = ',';
// 		}
// 		else
// 		{
// 			map->point[y][x].cord[Z] = ft_atoi(temp) * map->z_scale;
// 			map->point[y][x].color = WHITE;
// 		}
// 		// if (!is_valid_number(temp))
// 		// {
// 		// 	ft_error(ERROR_CHAR, 0);
// 		// 	free(line);
// 		// 	free_cord(map);
// 		// 	exit (0);
// 		// }
// 		map->point[y][x].cord[X] = (x + 0.5 - (map->with / 2));
// 		map->point[y][x].cord[Y] = (y + 0.5 - (map->hait / 2));
// 		while (*temp && (*temp == '-' || *temp == '+' || ft_isdigit(*temp)))
// 			temp++;
// 		if (*temp == ',')
// 		{
// 			temp++;
// 			while (*temp && (ft_isdigit(*temp) || (*temp >= 'a' && *temp <= 'f') \
// 			|| (*temp >= 'A' && *temp <= 'F') || *temp == 'x' || *temp == 'X'))
// 				temp++;
// 		}
// 		x++;
// 	}
// }

static void	map_cord_put(char *line, int y, t_map *map)
{
	int		x;
	char	**cells = ft_split(line, ' ');
	
	if (!cells)
	{
		ft_error(ERROR_INIT, 0);
		exit(1);
	}
	for (x = 0; x < map->with; x++)
	{
		char *cell = cells[x];
		char *comma = ft_strchr(cell, ',');
		printf("coma: %s\n", comma);
		if (comma)
		{
			*comma = '\0';
			map->point[y][x].cord[Z] = ft_atoi(cell) * map->z_scale;
			char *color_str = comma + 1;
			map->point[y][x].color = ft_atoi_base(color_str, 16);
			printf("assigned color[%d][%d]: %06X\n", y, x, map->point[y][x].color);
			// map->point[y][x].color = ft_atoi_base(color_str, 16);
			*comma = ',';
		}
		else
		{
			map->point[y][x].cord[Z] = ft_atoi(cell) * map->z_scale;
			map->point[y][x].color = WHITE;
		}
		map->point[y][x].cord[X] = (x + 0.5 - (map->with / 2));
		map->point[y][x].cord[Y] = (y + 0.5 - (map->hait / 2));
	}
	x = 0;
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
		// last_space(temp, map);
		map_cord_put(temp, y, map);
		free(line);
		y++;
	}
	close (fd);
}

static int	is_retangular(char **map_row, int prev_row, int *fd)
{
	int	x;

	x = 0;
	while (map_row[x] && (*map_row[x]) != '\n')
		x++;
	if (prev_row != -1 && prev_row != x)
	{
		close (*fd);
		ft_error(ERROR_FORMAT, 0);
		free_map(map_row);
		exit (0);
	}
	if (prev_row != -1)
		return (prev_row);
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

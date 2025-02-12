/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:54 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/12 17:32:05 by andcarva         ###   ########.fr       */
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
	int	x;
	char *temp;

	x = 0;
	temp = line;
	while (*temp && x < map->with)
	{
		while (*temp == ' ' || *temp == 9)
			temp++;
		if (!is_valid_number(temp))
		{
			ft_error(ERROR_CHAR, 0);
			free(line);
			free_cord(map);
			exit (0);
		}
		map->point[y][x].cord[X] = (x + 0.5 - (map->with / 2));
		map->point[y][x].cord[Y] = (y + 0.5 - (map->hait / 2));
		map->point[y][x].cord[Z] = ft_atoi(temp);
		// printf("cord1.x %f cord1.y %f cord1.z %f\n", map->point[y][x].cord[X], map->point[y][x].cord[Y], map->point[y][x].cord[Z]);
		// ft_printf("y: %d, x: %d, z: %d\n", y, x, (int)point[y][x].cord[Z]);
		while (*temp && (*temp == '-' || *temp == '+' || ft_isdigit(*temp)))
			temp++;
		x++;
	}
}

void	map_matriz(t_map *map, char *file)
{
	int		fd;
	int		y;
	char	*temp;
	char	*line;

	y = 0;
	fd = fd_check(file);
	// printf("Width -> %d, Height -> %d\n", map->with, map->hait);
	map->point = malloc(sizeof(t_point *) * (map->hait));
	if (!map->point)
		ft_error(ERROR_INIT, 0);
	line_memory(map->point, map->with, map->hait);
	//printf("1 - cord1.x %f cord1.y %f cord1.z %f\n", map->point[0][0].cord[X], map->point[0][0].cord[Y], map->point[0][0].cord[Z]);
	while (y < map->hait)
	{
		line = get_next_line(fd);
		temp = line;
		map_cord_put(temp, y, map);
		free(line);
		// printf("cord1.x %f cord1.y %f cord2.x %f cord2.y %f\n", map->point[y][0].cord[X], map->point[y][0].cord[Y], map->point[y][1].cord[X], map->point[y][1].cord[Y]);
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
	// ft_printf("prev: %d\n", prev_row);
	// ft_printf("x: %d\n", x);
	if (prev_row != -1 && prev_row != x)
	{
		close (*fd);
		ft_error(ERROR_FORMAT, 0);
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

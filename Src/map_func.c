/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:54 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/05 16:32:43 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	map_info(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd_check(&fd, file))
		exit (0);
	line = get_next_line(fd);
	if (!line)
		ft_error("Map empty!", 0);
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

static void	map_cord_put(char *line, int y, t_map *map, t_point ***point)
{
	int	x;

	x = 0;
	while (*line && x < map->with)
	{
		while (*line == ' ' || *line == 9)
			line++;
		point[y][x]->cord[X] = (x + 0.5 - (map->with / 2));
		point[y][x]->cord[Y] = (y + 0.5 - (map->hait / 2));
		point[y][x]->cord[Z] = atoi(line);
		// printf("AAAAAAAAAAAA\n");
		ft_printf("Line %d\n", atoi(line));
		ft_printf("y: %d, x: %d, z: %d\n", y, x, (int)(*point)[y][x].cord[Z]);
		while (*line >= '0' && *line <= '9')
			line++;
		x++;
	}
}

void	map_matriz(t_map *map, char *file)
{
	int		fd;
	int		y;
	char	*temp;
	char	*line;
	t_point	**points;

	y = 0;
	fd = open(file, O_RDONLY);
	points = malloc(sizeof(t_point *) * (map->hait + 1));
	if (!points)
		ft_error("Cord not initialized!", 0);
	while (y < map->hait)
	{
		points[y] = malloc(sizeof(t_point) * (map->with + 1));
		if (!points[y])
			ft_error("Cord not initialized!", 0);
		line = get_next_line(fd);
		temp = line;
		map_cord_put(temp, y, map, &points);
		// printf("Cord: %f\n", map->point.cord[y][x]);
		free(line);
		y++;
	}
	close (fd);
}


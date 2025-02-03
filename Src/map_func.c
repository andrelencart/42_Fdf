/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:54 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/03 18:59:53 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	map_info(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Map fd error!", 0);
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

static void	map_cord_put(char *line, int y, t_map *map)
{
	int	x;

	x = 0;
	while (*line && *line != '\n')
	{
		if (*line == ' ')
			line++;
		map->point.cord[y][x] = atoi(line);
		// ft_printf("Line %d\n", atoi(line));
		// ft_printf("y: %d, x: %d, z: %d\n", y, x, (int)map->point.cord[y][x]);
		while (*line >= '0' && *line <= '9')
			line++;
		x++;
	}
}

void	map_matriz(t_map *map, char *file)
{
	int		fd;
	char	*temp;
	char	*line;
	int		x;
	int		y;

	y = 0;
	fd = open(file, O_RDONLY);
	while (y < map->hait)
	{
		x = 0;
		map->point.cord[y] = malloc(sizeof(float) * (map->with + 1));
		if (!map->point.cord[y])
			ft_error("Cord not initialized!", 0);
		line = get_next_line(fd);
		temp = line;
		map_cord_put(temp, y, map);
		// printf("Cord: %f\n", map->point.cord[y][x]);
		free(line);
		y++;
	}
	close (fd);
}

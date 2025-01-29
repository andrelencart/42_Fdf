/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:06:58 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/29 19:44:26 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	window_init(t_window *wind)
{
	wind->mlx = mlx_init();
	wind->mlx_window = mlx_new_window(wind->mlx, WIDTH, HEIGHT, "Fdf by Andcarva");
	wind->img = mlx_new_image(wind->mlx, WIDTH, HEIGHT);
	wind->addr = mlx_get_data_addr(wind->img, &wind->bitpp, &wind->line_length, &wind->endian);
	// printf("mlx = %p\n", wind->mlx);
	// printf("window = %p\n", wind->mlx_window);
	// printf("img = %p\n", wind->img);
	// printf("addr = %p\n", wind->addr);
}

void	map_init(t_map *map, char *file)
{
	map->hait = 0;
	map->with = 0;
	map_info(map, file);
	map->point.cord = malloc(sizeof(float *) * (map->hait + 1));
	if (!map->point.cord)
		perror("Cord not initialized!");
	map_matriz(map, file);
}

void	map_info(t_map *map, char *file)
{
	int		fd;
	char	*line;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("Map fd error!");
	line = get_next_line(fd);
	if (!line)
		perror("Map empty!");
	map->mtz = ft_split(line, ' ');
	while (line)
	{
		map->hait++;
		free(line);
		line = get_next_line(fd);
	}
	while (map->mtz[map->with])
	{
		map->with++;
		free(map->mtz[map->with]);
	}
	free(map->mtz);
	free(line);
	close(fd);
}

void	map_matriz(t_map *map, char *file)
{
	int	fd;
	int	x;
	int	y;
	const char *line;
	
	y = 0;
	fd = open(file, O_RDONLY);
	while (y < map->hait)
	{
		x = 0;
		map->point.cord[y] = malloc(sizeof(float) * (map->with + 1));
		if (!map->point.cord[y])
			perror("Cord not initialized!");
		line = get_next_line(fd);
		while (*line && *line != '\n')
		{
			if (*line == ' ')
				line++;
			// printf("Val = %d\n", atoi(line));
			map->point.cord[y][x] = atoi(line);
			// printf("Line = %s\n", line);
			// printf("Cord = %d\n", (int)map->point.cord[y][x]);
			while ((*line >= '0' && *line <= '9'))
				line++;	
			x++;
		}
		map->point.cord[y][x] = 0;
		y++;
	}
	map->point.cord[y] = NULL;
}

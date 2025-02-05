/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:23:35 by andre             #+#    #+#             */
/*   Updated: 2025/02/05 18:39:13 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

bool	fd_check(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		ft_error("ERROR OPENING FILE", 0);
		return (true);
	}
	if (read(*fd, 0, 0) < 0)
	{
		ft_error("ERROR READING FILE", 0);
		close(*fd);
		return (true);
	}
	return (false);
}

void	error_extension(char *file)
{
	size_t	len;
	
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".fdf", 4) != '\0')
	{
		ft_error("WRONG EXTENSION!", 0);
		exit(1);
	}
}

void	map_format(char *file)
{
	char	**map_row;
	char	*line;
	int		fd;
	int		prev_row;
	int		x;
	int		y;

	fd = open(file, O_RDONLY);
	if(fd_check(&fd, file))
		exit (0);
	y = 0;
	prev_row = -1;
	while ((line = get_next_line(fd)))
	{
		map_row = ft_split(line, ' ');
		if (!map_row)
			return ;
		free(line);
		x = ft_strlen(map_row[x]);
		if (prev_row != -1 && prev_row != x)
		{
			close (fd);
			ft_error("MAP NOT RETANGULAR!", 0);
			exit (0);
		}
		prev_row = x;
		y++;
	}
	close (fd);
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:23:35 by andre             #+#    #+#             */
/*   Updated: 2025/02/05 16:41:15 by andcarva         ###   ########.fr       */
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

static void	error_extension(char *file)
{
	size_t	len;
	
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".fdf", 4) != '\0')
	{
		ft_error("WRONG EXTENSION!", 0);
		exit(1);
	}
}

static void	map_format(char *file)
{
	char **map;

	map = malloc(sizeof(char **));
	
}
void	parser(char *file)
{
	error_extension(file);
	map_format(file);
}



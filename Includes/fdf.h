/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:37:12 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/06 19:25:34 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>
# include <errno.h>
#include <stdbool.h>
# include "../Includes/Libft/libft.h"
# include "../minilibx-linux/mlx.h"

// MAP_DEF
# define WIDTH 1920
# define HEIGHT 1080

// KEY_DEF
# define ESC 65307

// COLOR_DEF
# define WHITE 0x00FFFFFF

// CORD_DEF
# define X 0
# define Y 1
# define Z 2

typedef	struct s_window
{
	void	*mlx;
	void	*mlx_window;
	void	*img;
	char	*addr;
	int		bitpp;
	int		line_length;
	int		endian;
}			t_window;

typedef struct s_point
{
	float 	cord[3];
	float	dx;
	float	dy;
	int		color;
}			t_point;

typedef struct s_map
{
	char 	**mtz;
	int		ang[3];
	int		z_max;
	int		z_min;
	int		scale;
	int		orig_cord[3];
	int		hait;
	int		with;
	t_point	**point;
}			t_map;

typedef struct s_fdf
{
	t_window	window;
	t_map		map;
}				t_fdf;

// INIT_FUNC
void	window_init(t_window *wind);
void	map_init(t_map *map, char *file);

// PARCER_FUNC
void	map_info(t_map *map, char *file);
void	map_matriz(t_map *map, char *file);
void	parser(t_map *map, char *file);
void	map_format(char *file);
void	error_extension(char *file);

// CLOSE_FUNC
int		window_close(t_window *wind);

// KEYBOARD
void	hook_control(t_window *wind);
int		key_press(int key_code, t_window *wind);

// DRAW_MAP
void	put_line(t_window *wind);
void	draw_map(t_map *map);
void	dda_alg(t_map *map, t_window *img);
void	dda_steps(t_point *point, t_window *img,t_point cord1, t_point cord2);

// UTILS
void		my_mlx_pixel_put(t_window *img, int x, int y, int color);
int			testkey(int key_code, t_window *wind);
int			key_press(int key_code, t_window *wind);
float		fabs_v(float n);
void		free_cord(t_map *map);
void		ft_error(char *error_msg, int sys_func);
int			fd_check(char *file);
void		free_map(char **map);


#endif // FDF_H
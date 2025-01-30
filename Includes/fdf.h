/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:37:12 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/30 17:35:13 by andcarva         ###   ########.fr       */
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
# include "../Includes/Libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 600
# define HEIGHT 400
# define ESC 65307

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
	float **cord;
	float	dx;
	float	dy;
}			t_point;

typedef struct s_map
{
	char **mtz;
	int	ang[3];
	int	z_max;
	int	z_min;
	int	scale;
	int	orig_cord[3];
	int	hait;
	int	with;
	t_point		point;
}		t_map;

typedef struct s_fdf
{
	t_window	window;
	t_map		map;
}				t_fdf;

// INIT_FUNC
void	window_init(t_window *wind);
void	map_init(t_map *map, char *file);

// MAP_FUNC
void	map_info(t_map *map, char *file);
void	map_matriz(t_map *map, char *file);

// CLOSE_FUNC
int	window_close(t_window *wind);

// KEYBOARD
void	hook_control(t_window *wind);
int		key_press(int key_code, t_window *wind);

// DRAW_MAP
void	put_line(t_window *wind);
void	draw_map(t_map *map);
void	map_delta(t_map *map);

// UTILS
void	my_mlx_pixel_put(t_window *img, int x, int y, int color);
int		testkey(int key_code, t_window *wind);
int		key_press(int key_code, t_window *wind);
int		abs_v(int n);
void	free_cord(t_map *map);


#endif // FDF_H
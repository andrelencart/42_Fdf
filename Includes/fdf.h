/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:37:12 by andcarva          #+#    #+#             */
/*   Updated: 2025/02/21 17:45:49 by andcarva         ###   ########.fr       */
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
# include <stdbool.h>
# include <math.h>
# include "../Includes/Libft/libft.h"
# include "../minilibx-linux/mlx.h"


// MAP_DEF
# define WIDTH 1920
# define HEIGHT 1080

// PROJECTION_KEYS
# define ISOMETRIC 0
# define FRONT_VIEW 1
# define SIDE_VIEW 2
# define TOP_VIEW 3

// MATH
# define PI 3.14159265358979323846

// KEY_DEF
# define ESC 65307
# define KBAR 65363
# define KBAL 65361
# define KBAU 65362
# define KBAD 65364
# define KB1 49
# define KB2 50
# define KB3 51
# define KB4 52
# define LA 65361
# define UP 65362
# define RA 65363
# define DOWN 65364
# define W 119
# define A 97
# define S 115
# define D 100

// COLOR_DEF
# define WHITE 0x00FFFFFF
# define BLACK 0x000000 

// CORD_DEF
# define X 0
# define Y 1
# define Z 2

// ERRORS
# define ERROR_ARGS "TO MANY ARGUMENTS"
# define ERROR_INIT "NOT INICIALIZED"
# define ERROR_MAP_LEN "MAP TO BIG"
# define ERROR_MAP "MAP EMPTY"
# define ERROR_SPACE "TO MANY SAPCES"
# define ERROR_CHAR "INVALID CHARACTER IN MAP"
# define ERROR_FORMAT "MAP NOT RETANGULAR"


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
	int		scale;
	int		orig_cord[3];
	int		hait;
	int		with;
	char	*file;
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
void	line_memory(t_point **points, int width, int height);
int		draw_img(t_fdf *fdf);
void	restart_map(t_map *map);

// PARCER_FUNC && UTILS
void	map_info(t_map *map, char *file);
void	map_matriz(t_map *map, char *file);
void	parser(t_map *map, char *file);
void	map_format(char *file);
void	error_extension(char *file);
bool	is_valid_number(char *str);
void	last_space(char *line, t_map *map);

// CLOSE_FUNC
int		window_close(t_window *wind, t_map *map);

// KEYBOARD
void	hook_control(t_fdf *fdf);
int		key_projection_change(int key_code, t_fdf *fdf);
int		key_press(int key_code, t_fdf *fdf);

// DRAW_MAP
void	dda_alg(t_map *map, t_window *img);
void	dda_steps(t_map *map, t_window *img,t_point cord1, t_point cord2);
void	draw_map(t_map *map, t_window *img);

// PROJECTIONS
void	top_v(t_map *map);
void	isometric(t_map *map);
void	side_v(t_map *map);
void	front_v(t_map *map);
void	projection_choice(t_map *map, int proj);

// ROTATIONS && TRANSLATIONS
void	rotation_x(t_map *map);
void	rotation_y(t_map *map);
void	rotation_z(t_map *map);
t_point	matxmul(float mat[3][3], t_point point);
void	translation(int	key_code, t_fdf *fdf);

// UTILS
void	my_mlx_pixel_put(t_window *img, int x, int y, int color);
int		testkey(int key_code, t_window *wind);
float	fabs_v(float n);
void	free_cord(t_map *map);
void	ft_error(char *error_msg, int sys_func);
int		fd_check(char *file);
void	free_map(char **map);


#endif // FDF_H
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:37:12 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/27 22:16:29 by andre            ###   ########.fr       */
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
	// t_map		*map;
	// t_point		*point;
}			t_window;

typedef struct s_map
{
	int	ang[3];
	int	z_max;
	int	z_min;
	int	scale;
	int	orig_cord[3];
	int	limt_x;
	int	limt_y;
}		t_map;

typedef struct s_point
{
	float	cord[3];
}			t_point;


// typedef struct s_fdf
// {
// 	t_window	*wind;
// 	t_map		*map;
// 	t_point		*point;
// }				t_fdf;

// INIT_FUNC
void	window_init(t_window *wind);


// CLOSE_FUNC
void	window_close(t_window *wind);

// KEYBOARD
void	hook_control(t_window *wind);
int		key_press(int key_code, t_window *wind);

// DRAW_MAP
void	put_line(t_window *wind);

// OTHERS
int		main(void);
void	my_mlx_pixel_put(t_window *img, int x, int y, int color);
int		testkey(int key_code, t_window *wind);
int		key_press(int key_code, t_window *wind);

#endif // FDF_H
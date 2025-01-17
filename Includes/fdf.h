/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:37:12 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/17 20:51:11 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>
# include "../Includes/Libft/libft.h"
# include "../MinilibX/minilibx-linux/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_fdf
{
	t_window	wind;
	t_map		*map;
	t_point		*point;
}				t_fdf;

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

// INIT_FUNC
void	window_init();

// CLOSE_FUNC
void	window_close(t_window *wind);
int		destroy(t_window *wind);

// OTHERS
int	main(void);
void	my_mlx_pixel_put(t_window *img, int x, int y, int color);
int		key_hook(t_window *wind);

#endif // FDF_H
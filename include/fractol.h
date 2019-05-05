/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 14:50:05 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 17:14:32 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>

# define WIN_WIDTH				500
# define WIN_HEIGHT				500
# define ABS(x) (x < 0 ? -x : x)

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_fract
{
	int				type;
	t_pos			min;
	t_pos			max;
	t_pos			mod;
	t_pos			cst;
	double			zoom;
	int				julias_bool;
	int				ite;
	int				r;
	int				g;
	int				b;
}					t_fract;

typedef struct		s_image
{
	void			*img;
	char			*ptr;
	int				bits;
	int				s_line;
	int				endian;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
	t_image			*img;
	t_fract			fract;
}					t_mlx;

int					error(char *msg);

int					key_hook(int key, t_mlx *mlx);
int					mouse_hook(int button, int x, int y, t_mlx *mlx);
int					julias_moove(int x, int y, t_mlx *mlx);

t_mlx				*del(t_mlx *mlx);
t_mlx				*init(char *title);

void				draw_image(t_image *img, int x, int y, int color);
void				reset_image(t_image *img);
t_image				*del_image(t_mlx *mlx, t_image *img);
t_image				*new_image(t_mlx *mlx);

void				change_color(int key, t_fract *fract);
int					get_color(int k, t_fract fract);
void				ft_zoom(int x, int y, t_mlx *mlx);
void				ft_dezoom(int x, int y, t_mlx *mlx);

void				init_mandelbrot(t_fract *fract);
void				draw_mandelbrot(t_mlx *mlx);

void				init_julia(t_fract *fract);
void				draw_julia(t_mlx *mlx);

void				init_burningship(t_fract *fract);
void				draw_burningship(t_mlx *mlx);

int					fract_strcmp(char *type, t_fract *fract);
void				init_fract(t_mlx *mlx);
void				draw_fract(t_mlx *mlx);

#endif

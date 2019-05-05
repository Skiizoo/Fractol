/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/23 12:36:38 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 12:36:48 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

void		init_mandelbrot(t_fract *fract)
{
	fract->min.x = -2.1;
	fract->min.y = -1.2;
	fract->zoom = 150;
	fract->ite = 100;
	fract->r = 255;
	fract->g = 255;
	fract->b = 255;
}

void		draw_mandelbrot(t_mlx *mlx)
{
	t_pos	pos;
	double	tmp;
	int		k;

	pos.x = -1;
	while (++pos.x < WIN_WIDTH && (pos.y = -1))
		while (++pos.y < WIN_HEIGHT && (k = -1))
		{
			mlx->fract.cst.x = pos.x / mlx->fract.zoom + mlx->fract.min.x;
			mlx->fract.cst.y = pos.y / mlx->fract.zoom + mlx->fract.min.y;
			mlx->fract.mod.x = 0;
			mlx->fract.mod.y = 0;
			while (mlx->fract.mod.x * mlx->fract.mod.x + mlx->fract.mod.y *
				mlx->fract.mod.y < 4 && ++k < mlx->fract.ite)
			{
				tmp = mlx->fract.mod.x;
				mlx->fract.mod.x = mlx->fract.mod.x * mlx->fract.mod.x -
					mlx->fract.mod.y * mlx->fract.mod.y + mlx->fract.cst.x;
				mlx->fract.mod.y = 2 * tmp * mlx->fract.mod.y +
					mlx->fract.cst.y;
			}
			k != mlx->fract.ite ? draw_image(mlx->img, pos.x, pos.y,
				get_color(k, mlx->fract)) : 0;
		}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 0, 0);
}

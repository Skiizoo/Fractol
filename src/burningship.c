/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   burningship.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/23 12:35:45 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 14:33:59 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

void		init_burningship(t_fract *fract)
{
	fract->min.x = -2.3;
	fract->min.y = -2.5;
	fract->zoom = 150;
	fract->ite = 50;
	fract->r = 75;
	fract->g = 150;
	fract->b = 100;
}

void		draw_burningship(t_mlx *mlx)
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
				/*mlx->fract.mod.x = ABS(mlx->fract.mod.x);
				mlx->fract.mod.y = ABS(mlx->fract.mod.y);
				tmp = mlx->fract.mod.x;
				mlx->fract.mod.x = mlx->fract.mod.x * mlx->fract.mod.x - mlx->fract.mod.y * mlx->fract.mod.y + mlx->fract.cst.x;
				mlx->fract.mod.y = 2 * tmp * mlx->fract.mod.y + mlx->fract.cst.y;*/

				tmp = mlx->fract.mod.x * mlx->fract.mod.x -
					mlx->fract.mod.y * mlx->fract.mod.y + mlx->fract.cst.x;
				mlx->fract.mod.y = ABS(2 * tmp * mlx->fract.mod.y) +
					mlx->fract.cst.y;
				mlx->fract.mod.x = tmp;
			}
			k != mlx->fract.ite ? draw_image(mlx->img, pos.x, pos.y,
					get_color(k, mlx->fract)) : 0;
		}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 0, 0);
}

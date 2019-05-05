/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/23 12:36:49 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 17:10:57 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

void		change_color(int key, t_fract *fract)
{
	fract->r = key == 15 ? 10 : 1;
	fract->g = key == 5 ? 10 : 1;
	fract->b = key == 11 ? 10 : 1;
}

int			get_color(int k, t_fract fract)
{
	return ((fract.r * k) % 256 << 16 | (fract.g * k) % 256 << 8 |
		(fract.b * k) % 256);
}

void		ft_zoom(int x, int y, t_mlx *mlx)
{
	t_fract	*fract;

	fract = &mlx->fract;
	fract->min.x = (x / fract->zoom + fract->min.x) - (x / (fract->zoom * 1.1));
	fract->min.y = (y / fract->zoom + fract->min.y) - (y / (fract->zoom * 1.1));
	fract->zoom *= 1.1;
	draw_fract(mlx);
}

void		ft_dezoom(int x, int y, t_mlx *mlx)
{
	t_fract	*fract;

	fract = &mlx->fract;
	fract->min.x = (x / fract->zoom + fract->min.x) - (x / (fract->zoom * 0.9));
	fract->min.y = (y / fract->zoom + fract->min.y) - (y / (fract->zoom * 0.9));
	fract->zoom *= 0.9;
	draw_fract(mlx);
}

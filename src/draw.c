/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/23 12:36:08 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 12:36:10 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

int			fract_strcmp(char *str, t_fract *fract)
{
	if (!ft_strcmp(str, "Mandelbrot"))
		fract->type = 0;
	else if (!ft_strcmp(str, "Julia"))
		fract->type = 1;
	else if (!ft_strcmp(str, "Burningship"))
		fract->type = 2;
	else
		return (0);
	return (1);
}

void		draw_fract(t_mlx *mlx)
{
	reset_image(mlx->img);
	if (!mlx->fract.type)
		draw_mandelbrot(mlx);
	else if (mlx->fract.type == 1)
		draw_julia(mlx);
	else if (mlx->fract.type == 2)
		draw_burningship(mlx);
}

void		init_fract(t_mlx *mlx)
{
	if (!mlx->fract.type)
		init_mandelbrot(&mlx->fract);
	else if (mlx->fract.type == 1)
		init_julia(&mlx->fract);
	else if (mlx->fract.type == 2)
		init_burningship(&mlx->fract);
	draw_fract(mlx);
}

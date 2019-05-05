/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/23 12:36:11 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 17:14:24 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

int			key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(0);
	else if (key == 15 || key == 11 || key == 5)
		change_color(key, &mlx->fract);
	else if (key == 34)
		init_fract(mlx);
	else if (key == 69)
		mlx->fract.ite++;
	else if (key == 78)
		mlx->fract.ite--;
	else if (key == 124)
		mlx->fract.min.x -= 30 / mlx->fract.zoom;
	else if (key == 123)
		mlx->fract.min.x += 30 / mlx->fract.zoom;
	else if (key == 126)
		mlx->fract.min.y += 30 / mlx->fract.zoom;
	else if (key == 125)
		mlx->fract.min.y -= 30 / mlx->fract.zoom;
	if (key == 15 || key == 11 || key == 5 || key == 69 || key == 78 ||
			key == 123 || key == 124 || key == 125 || key == 126)
		draw_fract(mlx);
	return (1);
}

int			mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5)
		ft_zoom(x, y, mlx);
	if (button == 4)
		ft_dezoom(x, y, mlx);
	if (button == 2)
		mlx->fract.julias_bool = mlx->fract.julias_bool ? 0 : 1;
	return (1);
}

int			julias_moove(int x, int y, t_mlx *mlx)
{
	if (mlx->fract.type == 1 && mlx->fract.julias_bool)
	{
		mlx->fract.cst.x = x / mlx->fract.zoom + mlx->fract.min.x;
		mlx->fract.cst.y = y / mlx->fract.zoom + mlx->fract.min.y;
		draw_fract(mlx);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_del.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/23 12:32:44 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/23 12:36:19 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

t_mlx		*del(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	mlx->img = del_image(mlx->mlx, mlx->img);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*init(char *title)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()) ||
		!(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
			WIN_HEIGHT, title)) ||
		!(mlx->img = new_image(mlx)))
		return (del(mlx));
	return (mlx);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/23 12:36:27 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 17:14:36 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

int		error(char *msg)
{
	if (!ft_strcmp(msg, "Usage"))
		ft_putendl("Usage ./Fractol \"Mandelbrot\",\"Julia\",\"Burningship\"");
	else
		ft_putendl(msg);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		return (error("Usage"));
	if (!(mlx = init("Fract'ol - tbroggi@le-101")))
		return (error("error at initialization"));
	if (!(fract_strcmp(argv[1], &mlx->fract)))
		return (error("Usage"));
	init_fract(mlx);
	mlx_key_hook(mlx->window, key_hook, mlx);
	mlx_mouse_hook(mlx->window, mouse_hook, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, julias_moove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 18:08:43 by lfabbro           #+#    #+#             */
/*   Updated: 2016/10/31 10:44:11 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			init_mlx(t_mlx *mlx)
{
	if ((mlx->ptr = mlx_init()) == NULL)
		return (-1);
	if ((mlx->win = mlx_new_window(mlx->ptr, WIN_X, WIN_Y, "FRACTOL")) == NULL)
		return (-1);
	return (0);
}

static void			calc_fractal(t_data *data)
{
	data->f->x = -1;
	data->f->y = -1;
	while (++data->f->x < WIN_X)
	{
		data->f->y = -1;
		while (++data->f->y < WIN_Y)
		{
			(*data->calc_fractal)(data->f);
			if (data->f->iter != data->f->iter_max)
				draw_pxl(data, data->f->x, data->f->y);
			else
				erase_pxl(data, data->f->x, data->f->y);
		}
	}
}

void				fractol_new_image(t_data *data)
{
	data->img->img_ptr = mlx_new_image(data->mlx->ptr, WIN_X, WIN_Y);
	data->img->img = mlx_get_data_addr(data->img->img_ptr, &data->img->bpx, \
			&data->img->s_line, &data->img->en);
	calc_fractal(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, \
			data->img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx->ptr, data->img->img_ptr);
}

int					fractol(char *fractal)
{
	t_data			*data;

	if ((data = new_data()) == NULL)
		return (-1);
	if (init_mlx(data->mlx) < 0)
		return (-1);
	set_mandelbrot(data);
	fractol_new_image(data);
	mlx_mouse_hook(data->mlx->win, zoom_hook, data);
	mlx_hook(data->mlx->win, KEY_PRESS, KEY_PRESS_MASK, key_hook, data);
	mlx_hook(data->mlx->win, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_hook, \
			data);
	mlx_loop(data->mlx->ptr);
	if (fractal)
		return (0);
	return (0);
}

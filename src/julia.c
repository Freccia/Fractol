/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 17:36:39 by lfabbro           #+#    #+#             */
/*   Updated: 2016/08/14 18:46:29 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		calc_julia(t_fractal *f)
{
	f->iter = 0;
	f->z.r = (f->x / f->zoom + f->x1) + f->mt_x / f->zoom;
	f->z.i = (f->y / f->zoom + f->y1) + f->mt_y / f->zoom;
	while (f->z.r * f->z.r + f->z.i * f->z.i < 4 && f->iter < f->iter_max)
	{
		f->tmp = f->z.r;
		f->z.r = (f->z.r * f->z.r) - (f->z.i * f->z.i) + f->c.r;
		f->z.i = 2 * (f->z.i * f->tmp) + f->c.i;
		++f->iter;
	}
}

int			set_julia(t_data *data)
{
	if ((data->f = (t_fractal*)malloc(sizeof(t_fractal))) == NULL)
		return (-1);
	data->calc_fractal = &calc_julia;
	data->set_fractal = &set_julia;
	data->f->x = -1;
	data->f->y = -1;
	data->f->x1 = -2.4;
	data->f->x2 = 1.2;
	data->f->y1 = -2;
	data->f->y2 = 1.8;
	data->f->mt_x = 0;
	data->f->mt_y = 0;
	data->f->c.i = 0.8;
	data->f->c.r = 0;
	data->f->z.i = 0;
	data->f->z.r = 0;
	data->f->tmp = 0;
	data->f->iter = 0;
	data->f->iter_max = ITER_MAX;
	data->f->zoom = ZOOM;
	data->f->curs_x = WIN_X / 2;
	data->f->curs_y = WIN_Y / 2;
	return (0);
}

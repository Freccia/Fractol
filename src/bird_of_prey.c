/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bird_of_prey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 18:23:59 by lfabbro           #+#    #+#             */
/*   Updated: 2016/08/16 13:33:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

void			calc_bird_of_prey(t_fractal *f)
{
	f->iter = 0;
	f->c.r = (f->x / f->zoom + f->x1) + f->mt_x / f->zoom;
	f->c.i = (f->y / f->zoom + f->y1) + f->mt_y / f->zoom;
	f->z.r = 0;
	f->z.i = 0;
	while ((f->z.r * f->z.r + f->z.i * f->z.i) < 4 && f->iter < f->iter_max)
	{
		f->tmp = f->z.i;
		f->z.i = (f->z.r * f->z.r * 3 - (f->z.i * f->z.i)) * fabs(f->z.i) \
				+ f->c.i;
		f->z.r = ((f->z.r * f->z.r) - (f->tmp * f->tmp * 3)) * fabs(f->z.r) \
				+ f->c.r;
		++f->iter;
	}
}

int				set_bird_of_prey(t_data *data)
{
	if ((data->f = (t_fractal*)malloc(sizeof(t_fractal))) == NULL)
		return (-1);
	data->calc_fractal = &calc_bird_of_prey;
	data->set_fractal = &set_bird_of_prey;
	data->f->x = -1;
	data->f->y = -1;
	data->f->x1 = -2.4;
	data->f->x2 = 1.2;
	data->f->y1 = -2;
	data->f->y2 = 1.8;
	data->f->mt_x = 0;
	data->f->mt_y = 0;
	data->f->c.i = 0;
	data->f->c.r = 0;
	data->f->z.i = 0;
	data->f->z.r = 0;
	data->f->tmp = 0;
	data->f->iter_max = ITER_MAX;
	data->f->zoom = ZOOM;
	data->f->curs_x = 0;
	data->f->curs_y = 0;
	return (0);
}

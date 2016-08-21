/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 17:36:49 by lfabbro           #+#    #+#             */
/*   Updated: 2016/08/16 13:31:07 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			zoom(int x, int y, t_fractal *f, double factor)
{
	double	tmp_x1;
	double	tmp_y1;
	double	tmp_x2;
	double	tmp_y2;

	tmp_x1 = f->x1 + x / f->zoom;
	tmp_y1 = f->y1 + y / f->zoom;
	tmp_x2 = f->x2 + x / f->zoom;
	tmp_y2 = f->y2 + y / f->zoom;
	f->zoom *= factor;
	f->x1 = tmp_x1 - (WIN_X / f->zoom) / 2;
	f->y1 = tmp_y1 - (WIN_Y / f->zoom) / 2;
	f->x2 = tmp_x2 + (WIN_X / f->zoom) / 2;
	f->y2 = tmp_y2 + (WIN_Y / f->zoom) / 2;
	if (factor > 1)
		f->iter_max += 5;
	else
		f->iter_max -= 5;
}

int				zoom_hook(int button, int x, int y, t_data *data)
{
	if (button == CLICK_LEFT || button == MOUSE_WHEEL_IN)
	{
		if (x >= 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
		{
			zoom(x, y, data->f, 2);
			fractol_new_image(data);
		}
	}
	else if (button == CLICK_RIGHT || button == MOUSE_WHEEL_OUT)
	{
		if (x >= 0 && x <= WIN_X && y >= 0 && y <= WIN_Y &&\
				data->f->zoom > 20.0)
		{
			zoom(x, y, data->f, 0.5);
			fractol_new_image(data);
		}
	}
	return (0);
}

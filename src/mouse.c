/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 15:56:17 by lfabbro           #+#    #+#             */
/*   Updated: 2016/08/14 19:33:49 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_hook(int x, int y, t_data *data)
{
	if (data->moove_mouse)
	{
		if (data->set_fractal == &set_julia)
		{
			if (x > 0 && x < WIN_X)
			{
				if (y > 0 && y < WIN_Y)
				{
					if (data->f->curs_x <= x && data->f->curs_y < y)
						data->f->c.i -= 0.07;
					else if (data->f->curs_x < x && data->f->curs_y >= y)
						data->f->c.r += 0.07;
					else if (data->f->curs_x >= x && data->f->curs_y > y)
						data->f->c.i += 0.07;
					else if (data->f->curs_x > x && data->f->curs_y <= y)
						data->f->c.r -= 0.07;
				}
				fractol_new_image(data);
			}
		}
		data->f->curs_x = x;
		data->f->curs_y = y;
	}
	return (0);
}

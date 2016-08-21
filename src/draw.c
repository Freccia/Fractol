/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 12:20:02 by lfabbro           #+#    #+#             */
/*   Updated: 2016/08/16 11:48:58 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void				erase_pxl(t_data *data, double x, double y)
{
	int		pxl;

	pxl = ((int)x * 4) + ((int)y * data->img->s_line);
	data->img->img[pxl] = 0;
}

void				draw_pxl(t_data *data, double x, double y)
{
	int		pxl;

	pxl = ((int)x * 4) + ((int)y * data->img->s_line);
	data->img->img[pxl] = data->colors->c1 * data->f->iter;
	data->img->img[++pxl] = (data->colors->c2 * data->f->iter);
	data->img->img[++pxl] = (data->colors->c3 * data->f->iter);
}

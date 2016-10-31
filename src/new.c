/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:16:18 by lfabbro           #+#    #+#             */
/*   Updated: 2016/10/31 10:44:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_img	*new_img(void)
{
	t_img		*img;

	if ((img = (t_img*)malloc(sizeof(t_img))) == NULL)
		return (NULL);
	img->img_ptr = NULL;
	img->img = NULL;
	img->bpx = 0;
	img->s_line = 0;
	img->en = 0;
	return (img);
}

t_mlx			*new_mlx(void)
{
	t_mlx		*mlx;

	if ((mlx = (t_mlx*)malloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	mlx->ptr = NULL;
	mlx->win = NULL;
	return (mlx);
}

t_colors		*new_colors(void)
{
	t_colors	*col;

	if ((col = (t_colors*)malloc(sizeof(t_colors))) == NULL)
		return (NULL);
	col->c1 = 0;
	col->c1 = 0;
	col->c1 = 0;
	return (col);
}

t_data			*new_data(void)
{
	t_data		*data;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	if ((data->mlx = new_mlx()) == NULL)
		return (NULL);
	if ((data->img = new_img()) == NULL)
		return (NULL);
	if ((data->colors = new_colors()) == NULL)
		return (NULL);
	color_set_1(data->colors);
	data->f = NULL;
	data->set_fractal = NULL;
	data->calc_fractal = NULL;
	data->moove_mouse = 1;
	data->music = 0;
	return (data);
}

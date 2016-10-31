/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:38:51 by lfabbro           #+#    #+#             */
/*   Updated: 2016/10/31 10:44:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static int		key_change_colors_set(int keycode, t_data *data)
{
	if (keycode == COLOR_SET_1)
	{
		color_set_1(data->colors);
		return (0);
	}
	else if (keycode == COLOR_SET_2)
	{
		color_set_2(data->colors);
		return (0);
	}
	else if (keycode == COLOR_SET_3)
	{
		color_set_3(data->colors);
		return (0);
	}
	else if (keycode == COLOR_SET_4)
	{
		color_set_4(data->colors);
		return (0);
	}
	return (1);
}

static int		key_mooves_hook(int keycode, t_data *data)
{
	if (keycode == UP_KEY)
	{
		data->f->mt_y -= 25;
		return (0);
	}
	else if (keycode == DOWN_KEY)
	{
		data->f->mt_y += 25;
		return (0);
	}
	else if (keycode == LEFT_KEY)
	{
		data->f->mt_x -= 25;
		return (0);
	}
	else if (keycode == RIGHT_KEY)
	{
		data->f->mt_x += 25;
		return (0);
	}
	return (1);
}

static int		key_iter_mouse_hook(int keycode, t_data *data)
{
	if (keycode == INCR_ITER_KEY)
	{
		data->f->iter_max += 1;
		fractol_new_image(data);
		return (0);
	}
	else if (keycode == DECR_ITER_KEY && data->f->iter_max > 1)
	{
		data->f->iter_max -= 1;
		fractol_new_image(data);
		return (0);
	}
	else if (keycode == MOUSE_ON_OFF_KEY)
	{
		if (data->moove_mouse == 1)
			data->moove_mouse = 0;
		else
			data->moove_mouse = 1;
		if (data->f->set > 0)
			data->f->set = -1;
		else
			data->f->set = 1;
		return (0);
	}
	return (1);
}

static int		key_hook_2(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		free_data(data);
		mlx_destroy_window(data->mlx->ptr, data->mlx->win);
		exit(0);
	}
	else if (keycode == RESET_KEY)
	{
		data->set_fractal(data);
		fractol_new_image(data);
	}
	else if (keycode == PLAY_MUSIC && !data->music)
	{
		system("afplay ./music/astral_cave.mp3 &");
		data->music = 1;
	}
	else if (keycode == STOP_MUSIC)
	{
		system("killall afplay");
		data->music = 0;
	}
	return (0);
}

int				key_hook(int keycode, t_data *data)
{
	key_hook_2(keycode, data);
	if (!key_iter_mouse_hook(keycode, data))
		fractol_new_image(data);
	if (!key_mooves_hook(keycode, data))
		fractol_new_image(data);
	if (!key_change_fractal_1(keycode, data))
		fractol_new_image(data);
	if (!key_change_fractal_2(keycode, data))
		fractol_new_image(data);
	if (!key_change_colors_set(keycode, data))
		fractol_new_image(data);
	if (!key_change_colors(keycode, data))
		fractol_new_image(data);
	return (0);
}

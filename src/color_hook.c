/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:06:27 by lfabbro           #+#    #+#             */
/*   Updated: 2016/08/16 14:24:38 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		key_change_colors_2(int keycode, t_data *data)
{
	if (keycode == BLUE_KEY_PLUS)
	{
		data->colors->c3 += 1;
		return (0);
	}
	else if (keycode == BLUE_KEY_MINUS)
	{
		data->colors->c3 -= 1;
		return (0);
	}
	return (1);
}

int				key_change_colors(int keycode, t_data *data)
{
	if (keycode == RED_KEY_PLUS)
	{
		data->colors->c1 += 1;
		return (0);
	}
	else if (keycode == RED_KEY_MINUS)
	{
		data->colors->c1 -= 1;
		return (0);
	}
	else if (keycode == GREEN_KEY_PLUS)
	{
		data->colors->c2 += 1;
		return (0);
	}
	else if (keycode == GREEN_KEY_MINUS)
	{
		data->colors->c2 -= 1;
		return (0);
	}
	return (key_change_colors_2(keycode, data));
}

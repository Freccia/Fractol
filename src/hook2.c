/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:35:10 by lfabbro           #+#    #+#             */
/*   Updated: 2016/10/31 10:44:05 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_change_fractal_2(int keycode, t_data *data)
{
	if (keycode == MANDELBROT_KEY)
	{
		free(data->f);
		set_mandelbrot(data);
		data->calc_fractal = &calc_mandelbrot;
		return (0);
	}
	else if (keycode == JULIA_KEY)
	{
		free(data->f);
		set_julia(data);
		data->calc_fractal = &calc_julia;
		return (0);
	}
	else if (keycode == BURNSHIP_KEY)
	{
		free(data->f);
		set_burnship(data);
		data->calc_fractal = &calc_burnship;
		return (0);
	}
	else if (keycode == BIRD_OF_PREY_KEY)
	{
		free(data->f);
		set_bird_of_prey(data);
		data->calc_fractal = &calc_bird_of_prey;
		return (0);
	}
	return (1);
}

int			key_change_fractal_1(int keycode, t_data *data)
{
	if (keycode == CELTIC_KEY)
	{
		free(data->f);
		set_celtic(data);
		data->calc_fractal = &calc_celtic;
		return (0);
	}
	else if (keycode == DRUID_KEY)
	{
		free(data->f);
		set_druid(data);
		data->calc_fractal = &calc_druid;
		return (0);
	}
	else if (keycode == BUFFALO_KEY)
	{
		free(data->f);
		set_buffalo(data);
		data->calc_fractal = &calc_buffalo;
		return (0);
	}
	else if (keycode == CUBIC_KEY)
	{
		free(data->f);
		set_cubic(data);
		data->calc_fractal = &calc_cubic;
		return (0);
	}
	return (1);
}

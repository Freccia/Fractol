/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:17:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/08/16 14:49:44 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				set_fractal(t_data *data, char *fractal)
{
	if (ft_strcmp(fractal, "Mandelbrot") == 0)
		set_mandelbrot(data);
	else if (ft_strcmp(fractal, "Julia") == 0)
		set_julia(data);
	else if (ft_strcmp(fractal, "Burningship") == 0)
		set_burnship(data);
	else if (ft_strcmp(fractal, "Bird of prey") == 0)
		set_bird_of_prey(data);
	else if (ft_strcmp(fractal, "Celtic") == 0)
		set_celtic(data);
	else if (ft_strcmp(fractal, "Druid") == 0)
		set_druid(data);
	else if (ft_strcmp(fractal, "Buffalo") == 0)
		set_buffalo(data);
	else if (ft_strcmp(fractal, "Cubic") == 0)
		set_cubic(data);
}

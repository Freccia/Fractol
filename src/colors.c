/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 16:19:55 by lfabbro           #+#    #+#             */
/*   Updated: 2016/08/15 22:53:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		color_set_1(t_colors *colors)
{
	colors->c1 = COLOR_1;
	colors->c2 = COLOR_2;
	colors->c3 = COLOR_3;
	colors->shade = SHADE;
}

void		color_set_2(t_colors *colors)
{
	colors->c1 = COLOR_4;
	colors->c2 = COLOR_5;
	colors->c3 = COLOR_6;
	colors->shade = SHADE;
}

void		color_set_3(t_colors *colors)
{
	colors->c1 = COLOR_7;
	colors->c2 = COLOR_8;
	colors->c3 = COLOR_9;
	colors->shade = SHADE;
}

void		color_set_4(t_colors *colors)
{
	colors->c1 = COLOR_10;
	colors->c2 = COLOR_11;
	colors->c3 = COLOR_12;
	colors->shade = SHADE;
}

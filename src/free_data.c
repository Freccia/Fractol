/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 15:05:04 by lfabbro           #+#    #+#             */
/*   Updated: 2016/08/16 00:04:47 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		free_data(t_data *data)
{
	if (data->music)
		system("killall afplay");
	if (data->f)
	{
		free(data->f);
		data->f = NULL;
	}
	if (data->colors)
	{
		free(data->colors);
		data->colors = NULL;
	}
	if (data->img)
	{
		free(data->img);
		data->img = NULL;
	}
}

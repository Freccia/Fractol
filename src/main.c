/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 17:35:00 by lfabbro           #+#    #+#             */
/*   Updated: 2016/10/31 10:44:22 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int				error_usage(void)
{
	ft_printf("Error.\n");
	ft_printf("Usage: ./fractol [Mandelbrot | Julia | Burningship | ");
	ft_printf("Bird of prey | Celtic | Druid | Buffalo | Cubic]\n");
	return (-1);
}

static int				check_name(char **argv)
{
	if (ft_strcmp("Mandelbrot", argv[1]) && ft_strcmp("Julia", argv[1]))
		if (ft_strcmp("Bird of prey", argv[1]))
			if (ft_strcmp("Burningship", argv[1]))
				if (ft_strcmp("Celtic", argv[1]))
					if (ft_strcmp("Druid", argv[1]))
						if (ft_strcmp("Buffalo", argv[1]))
							if (ft_strcmp("Cubic", argv[1]))
								return (1);
	return (0);
}

static void				print_menu_2(void)
{
	ft_printf("# Buffalo        ->  7                              #\n");
	ft_printf("# Cubic          ->  8                              #\n");
	ft_printf("#                                                   #\n");
	ft_printf("# Adjust Colors:                                    #\n");
	ft_printf("# Red            Plus -> h     Minus -> b           #\n");
	ft_printf("# Green          Plus -> j     Minus -> n           #\n");
	ft_printf("# Blue           Plus -> k     Minus -> m           #\n");
	ft_printf("#                                                   #\n");
	ft_printf("# Change Color Set:                                 #\n");
	ft_printf("# Color Set 1     ->  a                             #\n");
	ft_printf("# Color Set 2     ->  s                             #\n");
	ft_printf("# Color Set 3     ->  d                             #\n");
	ft_printf("# Color Set 4     ->  f (black)                     #\n");
	ft_printf("#                                                   #\n");
	ft_printf("#####################################################\033[0m");
}

static void				print_menu(void)
{
	ft_printf("\033[33m");
	ft_printf("#####################################################\n");
	ft_printf("#                                                   #\n");
	ft_printf("#                      MENU                         #\n");
	ft_printf("#                                                   #\n");
	ft_printf("# Moove Fractal: Arrows                             #\n");
	ft_printf("# Zoom In:       Click Left / Scroll Wheel          #\n");
	ft_printf("# Zoom Out:      Click Right / Scroll Wheel         #\n");
	ft_printf("# Iter Plus:     =                                  #\n");
	ft_printf("# Iter Minus:    -                                  #\n");
	ft_printf("# Reset Fractal: r                                  #\n");
	ft_printf("# Mooves Julia:  space                              #\n");
	ft_printf("# Change Druid:  space                              #\n");
	ft_printf("# Play Music:    [      (Only on Mac_OsX)           #\n");
	ft_printf("# Stop Music:    ]                                  #\n");
	ft_printf("#                                                   #\n");
	ft_printf("# Change Fractal:                                   #\n");
	ft_printf("# Mandelbrot     ->  1                              #\n");
	ft_printf("# Julia          ->  2                              #\n");
	ft_printf("# Burningship    ->  3                              #\n");
	ft_printf("# Bird of Prey   ->  4                              #\n");
	ft_printf("# Celtic         ->  5                              #\n");
	ft_printf("# Druid          ->  6                              #\n");
	print_menu_2();
}

int						main(int argc, char **argv)
{
	if (argc <= 1 || check_name(argv))
		return (error_usage());
	print_menu();
	return (fractol(argv[1]));
}

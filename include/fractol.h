/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 17:37:16 by lfabbro           #+#    #+#             */
/*   Updated: 2016/10/31 10:44:12 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "libft.h"

/*
**	ENVIRONMENT MACROS
*/
# define ZOOM				160
# define ITER_MAX			30
# define WIN_X				800
# define WIN_Y				700
# define COLOR_SET_1		0
# define COLOR_SET_2		1
# define COLOR_SET_3		2
# define COLOR_SET_4		3

/*
**	MOUSE_HOOK MACROS (X11)
*/
# define MOTIONNOTIFY		6
# define POINTERMOTIONMASK	(1L<<6)
# define KEY_PRESS			2
# define KEY_PRESS_MASK		3

/*
** COLOR SETS
*/
# define COLOR_1				0x19
# define COLOR_2				0x7
# define COLOR_3				0x0
# define COLOR_4				0x1
# define COLOR_5				0x15
# define COLOR_6				0x9
# define COLOR_7				0x23
# define COLOR_8				0x12
# define COLOR_9				0x11
# define COLOR_10				0
# define COLOR_11				0
# define COLOR_12				0
# define SHADE					0

/*
**	KEYS
*/
# define ESC_KEY			53
# define RESET_KEY			15
# define PLAY_MUSIC			33
# define STOP_MUSIC			30
# define INCR_ITER_KEY		24
# define DECR_ITER_KEY		27
# define MOUSE_ON_OFF_KEY	49
# define UP_KEY				125
# define DOWN_KEY			126
# define LEFT_KEY			124
# define RIGHT_KEY			123

/*
**	COLORS KEYS
*/
# define RED_KEY_PLUS		40
# define RED_KEY_MINUS		46
# define GREEN_KEY_PLUS		38
# define GREEN_KEY_MINUS	45
# define BLUE_KEY_PLUS		4
# define BLUE_KEY_MINUS		11

/*
**	FRACTALS KEYS
*/
# define MANDELBROT_KEY		18
# define JULIA_KEY			19
# define BURNSHIP_KEY		20
# define BIRD_OF_PREY_KEY	21
# define CELTIC_KEY			23
# define DRUID_KEY			22
# define BUFFALO_KEY		26
# define CUBIC_KEY			28

/*
**	MOUSE KEYS MACROS
*/
# define CLICK_LEFT			1
# define CLICK_RIGHT		2
# define MOUSE_WHEEL_IN		5
# define MOUSE_WHEEL_OUT	4

typedef struct					s_complex
{
	double						r;
	double						i;
}								t_complex;

typedef struct					s_colors
{
	int							c1;
	int							c2;
	int							c3;
	int							shade;
}								t_colors;

typedef struct					s_mlx
{
	void						*ptr;
	void						*win;
}								t_mlx;

typedef struct					s_img
{
	void						*img_ptr;
	char						*img;
	int							bpx;
	int							s_line;
	int							en;
}								t_img;

typedef struct					s_fractal
{
	double						x;
	double						y;
	double						x1;
	double						x2;
	double						y1;
	double						y2;
	t_complex					c;
	t_complex					z;
	double						tmp;
	int							iter;
	int							iter_max;
	double						zoom;
	double						mt_x;
	double						mt_y;
	int							curs_x;
	int							curs_y;
	int							set;
}								t_fractal;

typedef struct					s_data
{
	t_mlx						*mlx;
	t_img						*img;
	t_fractal					*f;
	t_colors					*colors;
	int							(*set_fractal)(struct s_data*);
	void						(*calc_fractal)(t_fractal*);
	int							moove_mouse;
	int							music;
}								t_data;

/*
**	FRACTOL
*/
int								fractol(char *fractal);
void							fractol_new_image(t_data *data);

/*
**	SET FRACTAL
*/
void							set_fractal(t_data *data, char *fractal);
int								set_mandelbrot(t_data *data);
int								set_julia(t_data *data);
int								set_burnship(t_data *data);
int								set_bird_of_prey(t_data *data);
int								set_celtic(t_data *data);
int								set_druid(t_data *data);
int								set_buffalo(t_data *data);
int								set_cubic(t_data *data);

/*
**	CALC FRACTAL
*/
void							calc_mandelbrot(t_fractal *f);
void							calc_julia(t_fractal *f);
void							calc_burnship(t_fractal *f);
void							calc_bird_of_prey(t_fractal *f);
void							calc_celtic(t_fractal *f);
void							calc_druid(t_fractal *f);
void							calc_buffalo(t_fractal *f);
void							calc_cubic(t_fractal *f);

/*
**	HOOK
*/
int								key_hook(int keyhook, t_data *data);
int								mouse_hook(int x, int y, t_data *data);
int								zoom_hook(int button, int x, int y, \
		t_data *data);
int								key_change_fractal_1(int keycode, t_data *data);
int								key_change_fractal_2(int keycode, t_data *data);
int								key_change_colors(int keycode, t_data *data);

/*
**	DRAW
*/
void							erase_pxl(t_data *data, double x, \
		double y);
void							draw_pxl(t_data *data, double x, \
		double y);

/*
**	COLOR SET
*/
void							color_set_1(t_colors *colors);
void							color_set_2(t_colors *colors);
void							color_set_3(t_colors *colors);
void							color_set_4(t_colors *colors);

/*
**	ZOOM
*/
void							zoom(int x, int y, t_fractal *f, double factor);

/*
**	NEW
*/
t_mlx							*new_mlx(void);
t_data							*new_data(void);

/*
**	FREE
*/
void							free_data(t_data *data);

#endif

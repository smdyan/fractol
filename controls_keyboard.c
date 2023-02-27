/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:04:19 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/12 03:05:17 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_macos.h"

static t_complex	dcalc(t_fractol *frl)
{
	double	a;
	double	b;

	a = fabs(frl->max.re - frl->min.re);
	b = fabs(frl->max.im - frl->min.im);
	return (init_complex(a, b));
}

static void	move(int key, t_fractol *frl)
{
	t_complex	delta;

	delta = dcalc(frl);
	if (key == A_LF)
	{
		frl->min.re -= delta.re * 0.05;
		frl->max.re -= delta.re * 0.05;
	}
	else if (key == A_RT)
	{
		frl->min.re += delta.re * 0.05;
		frl->max.re += delta.re * 0.05;
	}
	else if (key == A_UP)
	{
		frl->min.im += delta.im * 0.05;
		frl->max.im += delta.im * 0.05;
	}
	else if (key == A_DN)
	{
		frl->min.im -= delta.im * 0.05;
		frl->max.im -= delta.im * 0.05;
	}
	draw_fractal(frl);
}

static void	change_max_iteration(int key, t_fractol *frl)
{
	if (key == K_PL || key == N_PL)
	{
		if (frl->max_itr < 50)
			frl->max_itr += 1;
		else if (frl->max_itr < 1000000000)
			frl->max_itr = (int)(frl->max_itr * 1.05);
	}
	if (key == K_MN || key == N_MN)
	{
		if (frl->max_itr > 50)
			frl->max_itr = (int)(frl->max_itr * 0.95);
		else if (frl->max_itr > 1)
			frl->max_itr -= 1;
	}
	draw_fractal(frl);
}

static void	change_color_shift(t_fractol *frl)
{
	frl->shift = (frl->shift + 1) % 3;
	draw_fractal(frl);
}

int	key_press(int key, t_fractol *frl)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_R)
	{
		set_defaults(frl);
		draw_fractal(frl);
	}
	else if (key == K_MN || key == N_MN || key == K_PL || key == N_PL)
		change_max_iteration(key, frl);
	else if (key == A_LF || key == A_RT || key == A_UP || key == A_DN)
		move(key, frl);
	else if (key == K_C)
		change_color_shift(frl);
	return (0);
}

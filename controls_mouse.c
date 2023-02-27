/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:05:34 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/12 03:06:04 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_macos.h"

static double	interpolate(double start, double end, double intrn)
{
	return (start + ((end - start) * intrn));
}

int	zoom(int button, int x, int y, t_fractol *frl)
{
	t_complex	mouse;
	double		intrn;
	double		zoom;
	double		a;
	double		b;

	if (button == SCR_UP || button == SCR_DN)
	{
		a = (double)x / (WIDTH / (frl->max.re - frl->min.re));
		b = (double)y / (HEIGHT / (frl->max.im - frl->min.im));
		mouse = init_complex(a + frl->min.re, b * -1 + frl->max.im);
		if (button == SCR_UP)
			zoom = 0.80;
		else
			zoom = 1.20;
		intrn = 1.0 / zoom;
		frl->min.re = interpolate(mouse.re, frl->min.re, intrn);
		frl->min.im = interpolate(mouse.im, frl->min.im, intrn);
		frl->max.re = interpolate(mouse.re, frl->max.re, intrn);
		frl->max.im = interpolate(mouse.im, frl->max.im, intrn);
		draw_fractal(frl);
	}
	return (0);
}

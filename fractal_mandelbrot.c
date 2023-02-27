/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:09:05 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/12 03:09:21 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	i_mb(t_fractol *frl)
{
	int			itr;
	double		a;
	t_complex	z;

	itr = 0;
	z = init_complex(frl->c.re, frl->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && itr < frl->max_itr)
	{
		a = pow(z.re, 2.0) - pow(z.im, 2.0);
		z = init_complex(a + frl->c.re, 2.0 * z.re * z.im + frl->c.im);
		itr++;
	}
	return (itr);
}

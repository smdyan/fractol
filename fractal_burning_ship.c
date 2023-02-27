/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_burning_ship.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:07:54 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/12 03:08:17 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	i_bs(t_fractol *frl)
{
	int			itr;
	double		a;
	double		b;
	t_complex	z;

	itr = 0;
	z = init_complex(frl->c.re, frl->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && itr < frl->max_itr)
	{
		a = pow(z.re, 2.0) - pow(z.im, 2.0) + frl->c.re;
		b = -2.0 * fabs(z.re * z.im) + frl->c.im;
		z = init_complex(a, b);
		itr++;
	}
	return (itr);
}

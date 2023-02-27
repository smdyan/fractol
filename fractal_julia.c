/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:08:33 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/12 03:08:48 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	i_ju(t_fractol *frl)
{
	int			itrn;
	double		a;
	double		b;
	t_complex	z;

	itrn = 0;
	z = init_complex(frl->c.re, frl->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && itrn < frl->max_itr)
	{
		a = pow(z.re, 2.0) - pow(z.im, 2.0) + frl->k.re;
		b = 2.0 * z.re * z.im + frl->k.im;
		z = init_complex(a, b);
		itrn++;
	}
	return (itrn);
}

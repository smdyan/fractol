/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:09:41 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/12 03:09:56 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error_message.h"

t_image	*init_image(void *mlx)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		terminate(ERR_IMAGE_INIT);
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img->img)
		terminate(ERR_IMAGE_INIT);
	img->adr = mlx_get_data_addr(img->img, &(img->bpp), &(img->sz), &(img->en));
	return (img);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	set_defaults(t_fractol *frl)
{
	frl->max_itr = 50;
	frl->min = init_complex(-2.0, -2.0);
	frl->max.re = 2.0;
	frl->max.im = frl->min.im + (frl->max.re - frl->min.re) * HEIGHT / WIDTH;
	frl->k = init_complex(-0.4, 0.6);
	frl->shift = 0;
}

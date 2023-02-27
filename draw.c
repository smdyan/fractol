/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:06:55 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/12 03:07:34 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error_message.h"
#include "color.h"

static void	put_pixel(t_fractol *frl, int x, int y, t_color color)
{
	int	i;

	i = (x * frl->img->bpp / 8)
		+ (y * frl->img->sz);
	frl->img->adr[i] = color.ch[3];
	frl->img->adr[++i] = color.ch[2];
	frl->img->adr[++i] = color.ch[1];
	frl->img->adr[++i] = color.ch[0];
}

static void	draw_fractal_part(t_fractol *frl)
{
	int			y;
	int			x;
	t_color		color;

	y = frl->start_line;
	while (y < frl->finish_line)
	{
		frl->c.im = frl->max.im - y * frl->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			frl->c.re = frl->min.re + x * frl->factor.re;
			color = get_color(frl->formula(frl), frl);
			put_pixel(frl, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_fractal(t_fractol *frl)
{
	double	a;

	a = (frl->max.re - frl->min.re) / (WIDTH - 1);
	frl->factor = init_complex(a, (frl->max.im - frl->min.im) / (HEIGHT - 1));
	frl->start_line = 0;
	frl->finish_line = HEIGHT;
	draw_fractal_part(frl);
	mlx_put_image_to_window(frl->mlx, frl->win, frl->img->img, 0, 0);
}

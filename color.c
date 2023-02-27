/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:02:15 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/12 03:03:57 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	get_color(int iteration, t_fractol *frl)
{
	t_color	color;
	double	t;
	int		a;

	t = (double)iteration / frl->max_itr;
	color.ch[0] = 0;
	a = (0 + frl->shift) % 3 + 1;
	color.ch[a] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	a = (1 + frl->shift) % 3 + 1;
	color.ch[a] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	a = (2 + frl->shift) % 3 + 1;
	color.ch[a] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

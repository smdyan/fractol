/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:11:09 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/12 03:11:15 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	sign(const char **str)
{
	if (**str == '-')
	{
		*str = *str + 1;
		return (-1);
	}
	return (1);
}

double	stod(const char *str)
{
	double	rez;
	double	fact;
	int		point_seen;
	int		d;

	rez = 0;
	fact = sign(&str);
	point_seen = 0;
	while (*str)
	{
		if (*str == '.')
		{
			point_seen = 1;
			str++;
		}
		d = *str - '0';
		if (d >= 0 && d <= 9)
		{
			if (point_seen)
				fact /= 10.0f;
			rez = rez * 10.0f + (float)d;
		}
		str++;
	}
	return (rez * fact);
}

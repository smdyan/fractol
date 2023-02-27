/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:11:40 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/12 03:12:21 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

void	print_help(void)
{
	ft_putendl("Available parametres:");
	ft_putendl("-> Mandelbrot");
	ft_putendl("-> Julia");
	ft_putendl("-> Burning_ship");
}

static int	check_parameter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '.' || str[i] == '-' || str[i] == '+')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_parameters(char *str1, char *str2)
{
	if (check_parameter(str1) && check_parameter(str2))
		return (1);
	return (0);
}

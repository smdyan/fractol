/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:10:23 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/16 02:27:55 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error_message.h"

static int	(*get_formula(char *name)) (t_fractol *frl)
{
	size_t				i;
	int					(*formula)(t_fractol *frl);
	static t_formula	formulas[] = {{F1, &i_mb}, {F2, &i_ju}, {F3, &i_bs}};

	i = 0;
	formula = NULL;
	while (i < (sizeof(formulas) / sizeof(t_formula)))
	{
		if (ft_strequ(name, formulas[i].name))
			formula = formulas[i].formula;
		i++;
	}
	return (formula);
}

static t_fractol	*init_fractol(char *name, void *mlx)
{
	t_fractol	*frl;

	frl = (t_fractol *)malloc(sizeof(t_fractol));
	if (!frl)
		terminate(ERR_FRACTOL_INIT);
	frl->mlx = mlx;
	frl->win = mlx_new_window(mlx, WIDTH, HEIGHT, name);
	if (!frl->win)
		terminate(ERR_WINDOW_INIT);
	frl->img = init_image(mlx);
	set_defaults(frl);
	frl->formula = get_formula(name);
	if (!frl->formula)
		terminate(ERR_FRACTAL_NAME);
	mlx_hook(frl->win, 2, 0, key_press, frl);
	mlx_hook(frl->win, 17, 0, closer, frl);
	mlx_hook(frl->win, 4, 0, zoom, frl);
	return (frl);
}

static void	start(int argc, char **argv)
{
	t_fractol	*frl;
	void		*mlx;

	mlx = mlx_init();
	frl = init_fractol(argv[1], mlx);
	if (argc == 4)
		frl->k = init_complex(stod(argv[2]), stod(argv[3]));
	draw_fractal(frl);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2 || (argc == 4 && check_parameters(argv[2], argv[3])))
	{
		if (get_formula(argv[1]))
			start(argc, argv);
	}
	print_help();
	return (0);
}

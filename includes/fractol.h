/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:17:24 by smdyan            #+#    #+#             */
/*   Updated: 2022/02/13 11:32:38 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH		1000
# define HEIGHT		1000
# define THREADS	10
# define F1			"Mandelbrot"
# define F2			"Julia"
# define F3			"Burning_ship"

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdint.h>
# include <stdbool.h>

/*
** channel — alpha, red, green, blue color channels
*/

typedef struct s_color
{
	int8_t	ch[4];
}			t_color;

/*
**  Complex number
** re — real part
** im — imaginary part
*/

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

/*
** Image
** image          — image identifier
** data_addr      — image
** bpp            — depth of image
** size_line      — number of bytes used to store one line of image
** endian         — little or big endian
*/

typedef struct s_image
{
	void		*img;
	char		*adr;
	int			bpp;
	int			sz;
	int			en;
}				t_image;

/*
** Fract'ol
*/

/*
** mlx            — connection identifier
** win         	  — window identifier
** image          — information about image
** max_iteration  — maximum iteration
** min            — minimum real and imaginary parts of complex numbers
** max            — maximum real and imaginary parts of complex numbers
** factor         — dependency between complex numbers and pixels
** c              — complex number
** k              — constant complex number (only for Julia)
** start_line     — start line of fractal part 
** finish_line    — finish line of fractal part
** color_shift    — shift of color channels
** formula        — fractal formula
*/

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	t_image			*img;
	int				max_itr;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	int				start_line;
	int				finish_line;
	int				shift;
	int				(*formula)(struct s_fractol *fractol);
}					t_fractol;

/*
** Formula
** name    — name of fractal
** formula — formula of fractal
*/

typedef struct s_formula
{
	char		*name;
	int			(*formula)(t_fractol *fractol);
}				t_formula;

/*
** Functions
*/
t_image		*init_image(void *mlx);
t_complex	init_complex(double re, double im);
void		set_defaults(t_fractol *fractol);
void		draw_fractal(t_fractol *fractol);
int			i_mb(t_fractol *fractol);
int			i_ju(t_fractol *fractol);
int			i_bs(t_fractol *fractol);
t_color		get_color(int iteration, t_fractol *fractol);
int			closer(void *param);
int			key_press(int key, t_fractol *fractol);
int			zoom(int button, int x, int y, t_fractol *fractol);
void		terminate(char *s);
void		print_help(void);
int			check_parameters(char *str1, char *str2);
double		stod(const char *str);

#endif

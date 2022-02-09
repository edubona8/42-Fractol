/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_algs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:25:08 by ebonamic          #+#    #+#             */
/*   Updated: 2022/02/02 21:39:32 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	my_fabs(long double number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

void	mandelbrot_alg(t_data *image, t_complex z, double c_real, double c_im)
{
	double	temp;

	z.re = 0;
	z.im = 0;
	image->interations = 0;
	while (my_fabs(z.re) * my_fabs(z.re) + my_fabs(z.im) * my_fabs(z.im) < \
	4 && image->interations < image->max_iterations)
	{
		temp = z.re * z.re - z.im * z.im + c_real;
		z.im = 2 * z.re * z.im + c_im;
		z.re = temp;
		image->interations++;
	}
}

void	julia_alg(t_data *image, double c_real, double c_im )
{
	double	temp;

	image->interations = 0;
	while (my_fabs(c_real) * my_fabs(c_real) + my_fabs(c_im) * my_fabs(c_im) \
	< 4 && image->interations < image->max_iterations)
	{
		temp = (c_real * c_real - c_im * c_im) + image->julia.re;
		c_im = (2 * c_real * c_im) + image->julia.im;
		c_real = temp;
		image->interations++;
	}
}

void	burning_ship_alg(t_data *image, t_complex z, double c_real, double c_im)
{
	double	temp;

	z.re = 0;
	z.im = 0;
	image->interations = 0;
	while (my_fabs(z.re) * my_fabs(z.re) + my_fabs(z.im) * my_fabs(z.im) < \
	4 && image->interations < image->max_iterations)
	{
		temp = z.re * z.re - z.im * z.im + c_real;
		z.im = my_fabs(2 * z.re * z.im) + c_im;
		z.re = temp;
		image->interations++;
	}
}

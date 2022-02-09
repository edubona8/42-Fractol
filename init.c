/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:25:30 by ebonamic          #+#    #+#             */
/*   Updated: 2022/02/02 21:39:01 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia_complex(t_data *image, char *argv[])
{
	image->julia.re = my_atof(argv[2]);
	image->julia.im = my_atof(argv[3]);
	init_julia(image);
}

void	init_mandelbrot(t_data *image)
{
	image->width = 600;
	image->height = 600;
	image->max_iterations = 80;
	image->min_i = -2;
	image->max_i = 2;
	image->min_r = -2;
	image->max_r = 2;
	image->color_shift = 0;
	image->set_image = 'm';
	image->help = 0;
}

void	init_julia(t_data *image)
{
	image->width = 600;
	image->height = 600;
	image->max_iterations = 80;
	image->min_i = -2;
	image->max_i = 2;
	image->min_r = -2;
	image->max_r = 2;
	image->color_shift = 0;
	image->set_image = 'j';
	image->help = 0;
}

void	init_burning_ship(t_data *image)
{
	image->width = 600;
	image->height = 600;
	image->max_iterations = 80;
	image->min_i = -2;
	image->max_i = 2;
	image->min_r = -2;
	image->max_r = 2;
	image->color_shift = 0;
	image->set_image = 'b';
	image->help = 0;
}

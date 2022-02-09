/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:25:39 by ebonamic          #+#    #+#             */
/*   Updated: 2022/02/02 01:25:42 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color_shift(t_data *image)
{
	image->color_shift = (image->color_shift + 1) % 3;
	draw_fractal(image);
}

void	move(int keycode, t_data *image)
{
	long double	delta_real;
	long double	delta_imag;

	delta_real = image->max_r - image->min_r;
	delta_imag = image->max_i - image->min_i;
	if (keycode == ARROW_LEFT)
	{
		image->min_r -= delta_real * 0.05;
		image->max_r -= delta_real * 0.05;
	}
	else if (keycode == ARROW_RIGHT)
	{
		image->min_r += delta_real * 0.05;
		image->max_r += delta_real * 0.05;
	}
	else if (keycode == ARROW_UP)
	{
		image->min_i += delta_imag * 0.05;
		image->max_i += delta_imag * 0.05;
	}
	else if (keycode == ARROW_DOWN)
	{
		image->min_i -= delta_imag * 0.05;
		image->max_i -= delta_imag * 0.05;
	}
}

int	key_press(int keycode, t_data *image)
{
	if (keycode == 'c' || keycode == 'C')
		change_color_shift(image);
	move(keycode, image);
	ft_zoom(keycode, 0, 0, image);
	draw_fractal(image);
	if (keycode == 65307)
		close_window(image);
	if (keycode == 65451 || keycode == 65453)
		change_max_interations(image, keycode);
	return (0);
}

void	change_max_interations(t_data *image, int keycode)
{
	if (keycode == 65451)
		image->max_iterations += 10;
	if (keycode == 65453)
		image->max_iterations -= 10;
	draw_fractal(image);
}

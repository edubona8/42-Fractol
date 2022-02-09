/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:24:21 by ebonamic          #+#    #+#             */
/*   Updated: 2022/02/07 00:21:15 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *image, t_color color)
{
	int	i;

	i = (image->p_x * image->img.bits_per_pixel / 8)
		+ (image->p_y * image->img.line_length);
	image->img.addr[i] = color.channel[3];
	image->img.addr[++i] = color.channel[2];
	image->img.addr[++i] = color.channel[1];
	image->img.addr[++i] = color.channel[0];
}

t_color	get_color(t_data *image)
{
	t_color	color;
	double	t;

	t = (double)image->interations / image->max_iterations;
	color.channel[0] = 0;
	color.channel[(0 + image->color_shift) % 3 + 1] = \
	(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + image->color_shift) % 3 + 1] = \
		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + image->color_shift) % 3 + 1] = \
		(int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:24:58 by ebonamic          #+#    #+#             */
/*   Updated: 2022/02/02 02:30:59 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_to_real(t_data *image)
{
	double	range;

	range = image->max_r - image->min_r;
	return (image->p_x * (range / image->width) + image->min_r);
}

double	map_to_immaginary(t_data *image)
{
	double	range;

	range = image->max_i - image->min_i;
	return (image->p_y * (range / image->height) + image->min_i);
}

void	set_image(double c_real, double c_im, t_complex z, t_data *image)
{
	if (image->set_image == 'm')
		mandelbrot_alg(image, z, c_real, c_im);
	else if (image->set_image == 'j')
		julia_alg(image, c_real, c_im);
	else if (image->set_image == 'b')
		burning_ship_alg(image, z, c_real, c_im);
}

int	draw_fractal(t_data *image)
{
	t_complex	z;
	t_color		color;
	double		c_real;
	double		c_im;

	image->p_x = 0;
	while (image->p_x < image->width)
	{
		image->p_y = 0;
		while (image->p_y < image->height)
		{
			c_real = map_to_real(image);
			c_im = map_to_immaginary(image);
			set_image(c_real, c_im, z, image);
			color = get_color(image);
			put_pixel(image, color);
			image->p_y++;
		}
		image->p_x++;
	}
	draw_help(image);
	return (0);
}

void	draw_help(t_data *image)
{
	char	*s;

	s = ft_itoa(image->max_iterations);
	mlx_put_image_to_window(image->mlx_ptr, image->win_ptr,
		image->img.img, 0, 0);
	mlx_string_put(image->mlx_ptr, image->win_ptr, 5, 20, COLOR_SILVER,
		"Interations:");
	mlx_string_put(image->mlx_ptr, image->win_ptr, 85, 20, COLOR_SILVER, s);
	mlx_string_put(image->mlx_ptr, image->win_ptr, 450, 400, COLOR_SILVER,
		"Controls");
	mlx_string_put(image->mlx_ptr, image->win_ptr, 450, 430, COLOR_SILVER,
		"Zoom in        - W");
	mlx_string_put(image->mlx_ptr, image->win_ptr, 450, 460, COLOR_SILVER,
		"Zoom out       - S");
	mlx_string_put(image->mlx_ptr, image->win_ptr, 450, 490, COLOR_SILVER,
		"Color Shift    - C");
	mlx_string_put(image->mlx_ptr, image->win_ptr, 450, 520, COLOR_SILVER,
		"Move           - Arrows");
	mlx_string_put(image->mlx_ptr, image->win_ptr, 450, 550, COLOR_SILVER,
		"Zoom           - Scroll");
	mlx_string_put(image->mlx_ptr, image->win_ptr, 450, 580, COLOR_SILVER,
		"Iterations     - +/-");
	free(s);
}

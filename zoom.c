/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:26:08 by ebonamic          #+#    #+#             */
/*   Updated: 2022/02/04 17:23:15 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_zoom_calc(t_data *image, int x, int y, char direction);

static void	ft_zoom_calc(t_data *image, int x, int y, char direction)
{
	t_zoom	zoom;

	zoom.x_ratio = (double)x / image->width;
	zoom.y_ratio = (double)y / image->height;
	zoom.delta_re = image->max_r - image->min_r;
	zoom.delta_im = image->max_i - image->min_i;
	zoom.delta_delta_re = 0;
	zoom.delta_delta_im = 0;
	if (direction == ZOOM_IN)
	{
		zoom.delta_delta_re = ((1.0 / 1.05) * zoom.delta_re) - zoom.delta_re;
		zoom.delta_delta_im = ((1.0 / 1.05) * zoom.delta_im) - zoom.delta_im;
	}
	else if (direction == ZOOM_OUT)
	{
		zoom.delta_delta_re = (1.05 * zoom.delta_re) - zoom.delta_re;
		zoom.delta_delta_im = (1.05 * zoom.delta_im) - zoom.delta_im;
	}
	image->min_r -= (zoom.delta_delta_re * zoom.x_ratio);
	image->max_r += (zoom.delta_delta_re * (1.0 - zoom.x_ratio));
	image->max_i += (zoom.delta_delta_im * zoom.y_ratio);
	image->min_i -= (zoom.delta_delta_im * (1.0 - zoom.y_ratio));
}

int	ft_zoom(int keycode, int x, int y, t_data *image)
{
	if (keycode == SCROLL_DOWN || keycode == 's')
	{
		ft_zoom_calc(image, x, y, ZOOM_OUT);
		draw_fractal(image);
	}
	else if (keycode == SCROLL_UP || keycode == 'w')
	{
		ft_zoom_calc(image, x, y, ZOOM_IN);
		draw_fractal(image);
	}
	return (1);
}

void	invalid_input_2(char *argv[])
{
	char	*argtext;
	int		i;

	i = 3;
	argtext = argv[3];
	while (i < 4)
	{
		while (*argtext)
		{
			if (!ft_isdigit(*argtext) && *argtext != '-'
				&& *argtext != '.' && *argtext != ' '
				&& *argtext != '+')
			{
				ft_error();
				exit(0);
			}
			argtext++;
		}
		i++;
	}
}

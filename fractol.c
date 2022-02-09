/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:25:21 by ebonamic          #+#    #+#             */
/*   Updated: 2022/02/04 17:23:05 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *image)
{
	mlx_clear_window(image->mlx_ptr, image->win_ptr);
	mlx_loop_end(image->mlx_ptr);
	mlx_destroy_image(image->mlx_ptr, image->img.img);
	mlx_destroy_window(image->mlx_ptr, image->win_ptr);
	mlx_destroy_display(image->mlx_ptr);
	free(image->mlx_ptr);
	exit(0);
}

void	invalid_input_1(char *argv[])
{
	char	*argtext;
	int		i;

	i = 3;
	argtext = argv[2];
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

int	ft_error(void)
{
	printf(ANSI_COLOR_RED"ATTENTION: Not case sensitive\n"ANSI_COLOR_RESET);
	printf("Try: ./fractol <name>\n");
	printf("List of fractols:\nmandelbrot\nburning-ship\njulia RE IM\n");
	return (0);
}

void	fractol(t_data image)
{
	image.mlx_ptr = mlx_init();
	image.win_ptr = mlx_new_window(image.mlx_ptr,
			image.width, image.height, "Fract'ol");
	image.img.img = mlx_new_image(image.mlx_ptr, image.width, image.height);
	image.img.addr = mlx_get_data_addr(image.img.img, &image.img.bits_per_pixel,
			&image.img.line_length, &image.img.endian);
	mlx_hook(image.win_ptr, 3, 1L << 1, key_press, &image);
	mlx_hook(image.win_ptr, 17, 0L, close_window, &image);
	mlx_mouse_hook(image.win_ptr, ft_zoom, &image);
	mlx_loop_hook(image.mlx_ptr, draw_fractal, &image);
	mlx_loop(image.mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_data	image;

	if (argc < 2 || argc > 4)
		return (ft_error());
	if (ft_strcmp("mandelbrot", argv[1]))
		init_mandelbrot(&image);
	else if (ft_strcmp("burning-ship", argv[1]))
		init_burning_ship(&image);
	else if (ft_strcmp("julia", argv[1]))
	{
		if (!argv[2] || !argv[3])
			return (ft_error());
		invalid_input_1(argv);
		invalid_input_2(argv);
		init_julia_complex(&image, argv);
	}
	else
		return (ft_error());
	fractol(image);
	return (0);
}

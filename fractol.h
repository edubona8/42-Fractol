/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:41:16 by ebonamic          #+#    #+#             */
/*   Updated: 2022/02/04 17:05:28 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ZOOM_IN 1
# define ZOOM_OUT -1

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ARROW_LEFT	65361
# define ARROW_UP	65362
# define ARROW_RIGHT	65363
# define ARROW_DOWN	65364

# define COLOR_TUNDORA 0x444444
# define COLOR_SILVER 0xCCCCCC
# define ANSI_COLOR_RED      "\x1b[31m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_zoom
{
	double	x_ratio;
	double	y_ratio;
	double	delta_re;
	double	delta_im;
	double	delta_delta_re;
	double	delta_delta_im;
}				t_zoom;

typedef struct s_color
{
	int8_t	channel[4];
}	t_color;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_image_inf
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image_inf;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	int			max_iterations;
	int			interations;
	t_image_inf	img;
	int			p_x;
	int			p_y;
	long double	min_i;
	long double	max_i;
	long double	min_r;
	long double	max_r;
	int			color_shift;
	t_complex	julia;
	char		set_image;
	int			help;
}				t_data;

int			ft_signal(char c);
int			ft_iswhitespace(int c);
void		draw_help(t_data *image);
void		ft_bzero(void *str, size_t len);
void		change_max_interations(t_data *image, int keycode);
char		*ft_itoa(int n);
void		put_pixel(t_data *image, t_color color);
void		init_burning_ship(t_data *image);
void		burning_ship_alg(t_data *image, t_complex c, double z1, double z2);
void		set_image(double a, double b, t_complex c, t_data *image);
int			close_window(t_data *image);
int			ft_isspace(int argument);
int			ft_isdigit(int argument);
int			ft_strcmp(const char *str1, const char *str2);
void		init_julia_complex(t_data *image, char *argv[]);
void		init_julia(t_data *image);
double		my_atof(const char *str);
char		char_handler(char **number);
void		julia_alg(t_data *image, double c1, double c2 );
void		invalid_input_1(char *argv[]);
void		invalid_input_2(char *argv[]);
int			ft_error(void);
void		move(int keycode, t_data *image);
void		change_color_shift(t_data *image);
int			key_press(int keycode, t_data *image);
int			ft_zoom(int keycode, int x, int y, t_data *data);
double		map_to_immaginary(t_data *image);
double		map_to_real(t_data *image);
long double	my_fabs(long double number);
long int	rgb_color(t_data *image);
int			mlx_get_hex_trgb(int r, int g, int b);
int			draw_fractal(t_data *image);
void		init_mandelbrot(t_data *image);
void		mandelbrot_alg(t_data *image, t_complex c, double z1, double z2 );
t_color		get_color(t_data *image);

#endif

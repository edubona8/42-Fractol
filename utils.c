/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:25:57 by ebonamic          #+#    #+#             */
/*   Updated: 2022/02/02 03:55:10 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	char_handler(char **number)
{
	while (ft_isspace(**number))
		(*number)++;
	if (**number == '-')
	{
		(*number)++;
		return (1);
	}
	else
	{
		if (**number == '+')
			(*number)++;
		return (0);
	}
}

double	my_atof(const char *str)
{
	double	nbr;
	double	signal;
	int		n;

	nbr = 0;
	n = 0;
	signal = 1;
	while (ft_iswhitespace(*str))
		++str;
	if (*str == '+' || *str == '-')
		signal = ft_signal(*(str++));
	while (ft_isdigit(*str))
		nbr = (nbr * 10) + (*(str++) - '0');
	if (*str == '.')
		++str;
	while (ft_isdigit(*str) && ++n)
		nbr = (nbr * 10) + (*(str++) - '0');
	while (n-- > 0)
		nbr *= 0.10;
	return (nbr * signal);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2++)
		if (*str1++ == 0)
			return (1);
	return (0);
}

int	ft_isdigit(int argument)
{
	if (argument >= 48 && argument <= 57)
		return (1);
	return (0);
}

int	ft_isspace(int argument)
{
	if (argument == ' ')
		return (1);
	return (0);
}

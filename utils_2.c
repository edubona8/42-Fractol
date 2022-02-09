/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:25:49 by ebonamic          #+#    #+#             */
/*   Updated: 2022/02/02 03:53:32 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*aux;
	size_t	len;
	long	nb;

	nb = n;
	len = numlen(n);
	aux = malloc(sizeof(char) * (len + 1));
	if (aux == 0)
		return (NULL);
	if (nb < 0)
	{
		aux[0] = '-';
		nb = -nb;
	}
	aux[len--] = '\0';
	if (nb == 0)
		aux[0] = '0';
	while (nb)
	{
		aux[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (aux);
}

void	ft_bzero(void *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
}

int	ft_iswhitespace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_signal(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

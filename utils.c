/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclarenn <aclarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:15:32 by aclarenn          #+#    #+#             */
/*   Updated: 2023/06/12 18:19:19 by aclarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

double	ft_get_dec(const char *str)
{
	double	nb;
	double	dec;
	int		i;
	int		j;

	nb = 0.0;
	dec = 0.0;
	i = 0;
	j = 0;
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10.0) + (*(str++) - '0');
	if (*(str++) == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			dec = (dec * 10.0) + (*(str++) - '0');
			i++;
		}
	}
	while (j++ < i)
		dec /= 10.0;
	if (*str == ',')
		return (nb + dec);
	return (nb + dec);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	res;

	res = 0.0;
	sign = 1;
	if (!*str)
		return (0);
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = ft_get_dec(str);
	return (res * sign);
}

void	ft_putendl(const char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}

void	error_msg(void)
{
	ft_putendl("Usage			: ./a.out <name> <real> <imaginary>");
	ft_putendl("");
	ft_putendl("<name>			: Mandelbrot or Julia");
	ft_putendl("<real> <imaginary>	: Only with Julia set");
	exit(0);
}

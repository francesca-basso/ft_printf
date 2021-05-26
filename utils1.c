/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:34:46 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/06 17:13:52 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *str, int *i)
{
	unsigned int	result;
	int				sign;

	result = 0;
	sign = 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = (result * 10) + (str[*i] - '0');
		if (result > 2147483647)
			break ;
		(*i)++;
	}
	if ((sign == -1 && result == 2147483648) || result <= 2147483647)
		return (result * sign);
	return (sign < 0 ? -1 : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:40:21 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/08 09:09:01 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_precision_unsigned(t_option *lst, int i)
{
	if (i == 0 && lst->precision.value == 0 && lst->width.present)
	{
		write(1, " ", 1);
		lst->counter++;
	}
}

void	ft_check_neg_unsigned(int i)
{
	if (i < 0)
	{
		i *= -1;
		i = 4294967296 - i;
	}
}

void	ft_check_width_unsigned(t_option *lst, int len)
{
	lst->width.value -= lst->precision.present ? lst->precision.value : len;
	lst->counter += len;
	ft_check_unsigned(lst, len);
}

int		ft_unsigned_int(t_option *lst, va_list *arg, int j)
{
	long	i;
	int		len;
	char	*s;
	int		x;
	int		precision;

	x = 0;
	if (lst->precision.present)
		precision = lst->precision.value;
	i = va_arg(*arg, unsigned int);
	ft_convert(i, 10);
	ft_check_precision_unsigned(lst, i);
	ft_check_neg_unsigned(i);
	s = ft_itoa2(i);
	if (lst->precision.present && !precision && !i)
	{
		while (s[x])
			s[x++] = 0;
	}
	len = ft_strlen(s);
	ft_check_width_unsigned(lst, len);
	ft_putstr(s);
	ft_check_flag_unsigned(lst);
	return (j);
}

void	ft_check_pointer(int i, t_option *lst)
{
	if (i == 0 && !lst->precision.present)
		lst->width.value--;
	while (lst->width.present && !lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		ft_putchar(' ');
		lst->counter++;
	}
}

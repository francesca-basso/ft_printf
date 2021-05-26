/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:38:53 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/06 17:39:20 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_precision_int(t_option *lst, int i)
{
	if (i == 0 && lst->precision.value == 0 && lst->width.present)
	{
		write(1, " ", 1);
		lst->counter++;
	}
}

void	ft_check_width_int(t_option *lst, int len, int i)
{
	if (i < 0 && !lst->flags[F_MINUS])
		lst->width.value--;
	lst->width.value -= lst->precision.present ? lst->precision.value : len;
	lst->counter += len;
	ft_check_int(lst, len, i);
}

int		ft_int(t_option *lst, va_list *arg, int j)
{
	int		i;
	int		len;
	char	*s;
	int		x;
	int		precision;

	x = 0;
	if (lst->precision.present)
		precision = lst->precision.value;
	i = va_arg(*arg, int);
	ft_convert(i, 10);
	ft_check_precision_int(lst, i);
	s = ft_itoa(i);
	if (lst->precision.present && !precision && !i)
	{
		while (s[x])
			s[x++] = 0;
	}
	len = ft_strlen(s);
	ft_check_width_int(lst, len, i);
	ft_putstr(s);
	ft_check_flag_int(lst);
	return (j);
}

void	ft_check_hex(t_option *lst, int len)
{
	if (lst->width.present &&
			lst->precision.present && lst->width.value > lst->precision.value)
		lst->width.value--;
	if (lst->flags[F_ZERO] && lst->width.value > lst->precision.value)
		lst->width.value = len - lst->precision.value;
	while (lst->width.present && !lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		write(1, lst->flags[F_ZERO] ? "0" : " ", 1);
		lst->counter++;
	}
	while (lst->precision.present && lst->precision.value-- > len)
	{
		ft_putchar('0');
		lst->counter++;
	}
}

void	ft_check_precision_hex(t_option *lst, int i)
{
	if (i == 0 && lst->precision.value == 0 && lst->width.present)
	{
		write(1, " ", 1);
		lst->counter++;
	}
}

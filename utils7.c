/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:39:33 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/06 17:44:37 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag_hex(t_option *lst)
{
	while (lst->width.present && lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		write(1, " ", 1);
		lst->counter++;
	}
}

int		ft_hex_lower(t_option *lst, va_list *arg, int j)
{
	unsigned int	i;
	int				len;
	char			*s;
	int				x;
	int				precision;

	x = 0;
	if (lst->precision.present)
		precision = lst->precision.value;
	i = va_arg(*arg, unsigned int);
	s = ft_convert(i, 16);
	ft_check_precision_hex(lst, i);
	if (lst->precision.present && !precision && !i)
	{
		while (s[x])
			s[x++] = 0;
	}
	len = ft_strlen(s);
	lst->width.value -= lst->precision.present ? lst->precision.value : len;
	lst->counter += len;
	ft_check_hex(lst, len);
	ft_putstr(s);
	ft_check_flag_hex(lst);
	return (j);
}

int		ft_hex_upper(t_option *lst, va_list *arg, int j)
{
	unsigned int	i;
	int				len;
	char			*s;
	int				x;
	int				precision;

	x = 0;
	if (lst->precision.present)
		precision = lst->precision.value;
	i = va_arg(*arg, unsigned int);
	s = ft_convert2(i, 16);
	ft_check_precision_hex(lst, i);
	if (lst->precision.present && !precision && !i)
	{
		while (s[x])
			s[x++] = 0;
	}
	len = ft_strlen(s);
	lst->width.value -= lst->precision.present ? lst->precision.value : len;
	lst->counter += len;
	ft_check_hex(lst, len);
	ft_putstr(s);
	ft_check_flag_hex(lst);
	return (j);
}

void	ft_check_unsigned(t_option *lst, int len)
{
	if (lst->width.present && lst->precision.present &&
			lst->width.value > lst->precision.value)
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

void	ft_check_flag_unsigned(t_option *lst)
{
	while (lst->width.present && lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		write(1, " ", 1);
		lst->counter++;
	}
}

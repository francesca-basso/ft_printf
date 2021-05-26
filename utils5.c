/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:38:06 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/06 17:35:44 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(t_option *lst, va_list *arg, int j)
{
	char	c;

	c = va_arg(*arg, int);
	lst->counter++;
	lst->width.value--;
	while (lst->width.present && !lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		ft_putchar(' ');
		lst->counter++;
	}
	ft_putchar(c);
	while (lst->width.present && lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		ft_putchar(' ');
		lst->counter++;
	}
	return (j);
}

int		ft_string(t_option *lst, va_list *arg, int j)
{
	char	*s;
	int		len;

	s = va_arg(*arg, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	lst->width.value = lst->width.value - (lst->precision.present &&
			len > lst->precision.value ? lst->precision.value : len);
	lst->counter += lst->precision.present &&
		len > lst->precision.value ? lst->precision.value : len;
	while (lst->width.present && !lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		ft_putchar(' ');
		lst->counter++;
	}
	write(1, s, lst->precision.present &&
			len > lst->precision.value ? lst->precision.value : len);
	while (lst->width.present && lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		ft_putchar(' ');
		lst->counter++;
	}
	return (j);
}

void	ft_check_neg_int(t_option *lst, int i)
{
	if (i < 0 && lst->flags[F_ZERO] && i != -2147483648)
	{
		ft_putchar('-');
		lst->counter++;
	}
}

void	ft_check_int(t_option *lst, int len, int i)
{
	if (lst->width.present &&
			lst->precision.present && lst->width.value > lst->precision.value)
		lst->width.value--;
	ft_check_neg_int(lst, i);
	if (lst->flags[F_ZERO] && lst->width.value > lst->precision.value)
		lst->width.value = len - lst->precision.value;
	while (lst->width.present && !lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		write(1, lst->flags[F_ZERO] ? "0" : " ", 1);
		lst->counter++;
	}
	if (i < 0 && !lst->flags[F_ZERO] && i != -2147483648)
	{
		ft_putchar('-');
		lst->width.value--;
		lst->counter++;
	}
	while (lst->precision.present && lst->precision.value-- > len)
	{
		ft_putchar('0');
		lst->counter++;
	}
}

void	ft_check_flag_int(t_option *lst)
{
	while (lst->width.present && lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		write(1, " ", 1);
		lst->counter++;
	}
}

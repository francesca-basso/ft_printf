/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:41:55 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/06 17:06:11 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag_pointer(t_option *lst)
{
	while (lst->width.present && lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		ft_putchar(' ');
		lst->counter++;
	}
}

int		ft_pointer(t_option *lst, va_list *arg, int j)
{
	size_t	i;
	int		len;
	char	*s;

	i = (size_t)va_arg(*arg, void *);
	s = ft_convert4(i, 16);
	len = ft_strlen(s) + 2;
	lst->width.value = lst->width.value - len;
	lst->counter += len;
	ft_check_pointer(i, lst);
	ft_putchar('0');
	ft_putchar('x');
	if (i == 0 && !lst->precision.present)
	{
		write(1, "0", 1);
		lst->counter++;
	}
	ft_putstr(s);
	ft_check_flag_pointer(lst);
	return (j);
}

int		ft_percent(t_option *lst, int j)
{
	lst->width.value -= 1;
	lst->counter += 1;
	while (lst->width.present && !lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		write(1, lst->flags[F_ZERO] ? "0" : " ", 1);
		lst->counter++;
	}
	ft_putchar('%');
	while (lst->width.present && lst->flags[F_MINUS] && lst->width.value-- > 0)
	{
		ft_putchar(' ');
		lst->counter++;
	}
	return (j);
}

void    ft_neg_width(t_option *lst)
{
    if (lst->width.value < 0)
    {
        lst->flags[F_MINUS] = TRUE;
        lst->flags[F_ZERO] = FALSE;
        lst->width.value *= -1;
    }
}

void	ft_neg_precision(t_option *lst)
{
	if (lst->precision.present && lst->precision.value < 0)
		lst->precision.present = FALSE;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:06:19 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/06 17:10:12 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_type(const char *input, t_option *lst, va_list *arg, int j)
{
	if (input[j] == 'c')
		j = ft_char(lst, arg, j);
	if (input[j] == 's')
		j = ft_string(lst, arg, j);
	if (input[j] == 'd' || input[j] == 'i')
		j = ft_int(lst, arg, j);
	if (input[j] == 'x')
		j = ft_hex_lower(lst, arg, j);
	if (input[j] == 'X')
		j = ft_hex_upper(lst, arg, j);
	if (input[j] == 'u')
		j = ft_unsigned_int(lst, arg, j);
	if (input[j] == 'p')
		j = ft_pointer(lst, arg, j);
	if (input[j] == '%')
		j = ft_percent(lst, j);
}

int		ft_check_all(const char *input, t_option *lst, va_list *arg, int j)
{
	j = ft_check_flag(input, lst, j);
	j = ft_check_width(input, lst, arg, j);
	ft_neg_width(lst);
	j = ft_check_precision(input, lst, arg, j);
	ft_neg_precision(lst);
	ft_check_type(input, lst, arg, j);
	return (j + 1);
}

int		ft_printf(const char *input, ...)
{
	int			j;
	t_option	lst;
	va_list		arg;

	j = 0;
	lst.counter = 0;
	va_start(arg, input);
	while (input[j])
	{
		if (input[j] != '%')
		{
			lst.counter++;
			ft_putchar(input[j++]);
		}
		else if (input[j] == '%')
		{
			j++;
			j = ft_check_all(input, &lst, &arg, j);
		}
	}
	va_end(arg);
	return (lst.counter);
}

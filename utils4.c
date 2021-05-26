/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:37:18 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/06 17:30:03 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getlen2(unsigned int n)
{
	int	i;

	i = 1;
	while (i < 10)
	{
		if (ft_isdigit(n + 48))
			break ;
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa2(unsigned int n)
{
	char	*a;
	int		len;

	len = getlen2(n);
	if (!(a = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	a[len] = '\0';
	a = convert2(a, n, len);
	return (a);
}

int		ft_check_flag(const char *input, t_option *lst, int j)
{
	lst->flags[F_MINUS] = FALSE;
	lst->flags[F_ZERO] = FALSE;
	while (input[j] && (input[j] == '-' || input[j] == '0'))
	{
		if (input[j] == '-')
			lst->flags[F_MINUS] = TRUE;
		if (input[j] == '0')
			lst->flags[F_ZERO] = TRUE;
		j++;
	}
	if (lst->flags[F_MINUS])
		lst->flags[F_ZERO] = FALSE;
	return (j);
}

int		ft_check_width(const char *input, t_option *lst, va_list *arg, int j)
{
	lst->width.present = FALSE;
	if (ft_isdigit(input[j]))
	{
		lst->width.present = TRUE;
		lst->width.value = ft_atoi(input, &j);
	}
	else if (input[j] == '*')
	{
		lst->width.present = TRUE;
		lst->width.value = va_arg(*arg, int);
		j++;
	}
	return (j);
}

int		ft_check_precision(const char *input,
							t_option *lst, va_list *arg, int j)
{
	lst->precision.present = FALSE;
	if (input[j] == '.')
	{
		j++;
		lst->precision.present = TRUE;
		if (ft_isdigit(input[j]))
			lst->precision.value = ft_atoi(input, &j);
		else if (input[j] == '*')
		{
			lst->precision.value = va_arg(*arg, int);
			j++;
		}
		else
			lst->precision.value = 0;
	}
	if (lst->precision.present)
		lst->flags[F_ZERO] = FALSE;
	return (j);
}

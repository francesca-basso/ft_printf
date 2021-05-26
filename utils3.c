/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:36:42 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/06 17:24:55 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s1[i])
		i++;
	if (!(ptr = (char *)malloc(i + 1)))
		return (0);
	ft_strlcpy(ptr, s1, (size_t)i + 1);
	return (ptr);
}

static int	getlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (i < 10)
	{
		if (ft_isdigit(n + 48))
			break ;
		n = n / 10;
		i++;
	}
	return (i);
}

static void	convert(char *a, int n, int len)
{
	if (n >= 0)
	{
		while (len-- > 0)
		{
			a[len] = (n % 10) + 48;
			n /= 10;
		}
	}
	else
	{
		n *= -1;
		while (len-- > 0)
		{
			a[len] = (n % 10) + 48;
			n /= 10;
		}
	}
}

char		*ft_itoa(int n)
{
	char	*a;
	int		len;

	len = getlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(a = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	a[len] = '\0';
	convert(a, n, len);
	return (a);
}

char	*convert2(char *a, unsigned int n, int len)
{
	while (len-- > 0)
	{
		a[len] = (n % 10) + 48;
		n /= 10;
	}
	n *= -1;
	while (len-- > 0)
	{
		a[len] = (n % 10) + 48;
		n /= 10;
	}
	return (a);
}
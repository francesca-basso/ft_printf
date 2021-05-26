/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:36:17 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/06 17:20:17 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert(unsigned int nmb, int base)
{
	static char sys_hex[] = "0123456789abcdef";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (!nmb)
		*--ptr = '0';
	while (nmb)
	{
		*--ptr = sys_hex[nmb % base];
		nmb /= base;
	}
	return (ptr);
}

char	*ft_convert2(unsigned int nmb, int base)
{
	static char sys_hex[] = "0123456789ABCDEF";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (!nmb)
		*--ptr = '0';
	while (nmb)
	{
		*--ptr = sys_hex[nmb % base];
		nmb /= base;
	}
	return (ptr);
}

char	*ft_convert3(unsigned long nmb, int base)
{
	static char sys_hex[] = "0123456789ABCDEF";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (nmb)
	{
		*--ptr = sys_hex[nmb % base];
		nmb /= base;
	}
	return (ptr);
}

char	*ft_convert4(size_t nmb, int base)
{
	static char sys_hex[] = "0123456789abcdef";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (nmb)
	{
		*--ptr = sys_hex[nmb % base];
		nmb /= base;
	}
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

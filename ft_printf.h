/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbasso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:09:36 by fbasso            #+#    #+#             */
/*   Updated: 2021/02/08 09:42:56 by fbasso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define FALSE 0
# define TRUE 1
# define F_MINUS 0
# define F_ZERO 1

typedef struct	s_int_v
{
	short		present;
	int			value;
}				t_int_v;

typedef struct	s_option
{
	short		flags[2];
	t_int_v		width;
	t_int_v		precision;
	int			counter;
}				t_option;

void			ft_putchar(char c);
void			ft_putstr(char *s);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
int				ft_atoi(const char *str, int *i);
char			*ft_convert(unsigned int nmb, int base);
char			*ft_convert2(unsigned int nmb, int base);
char			*ft_convert3(unsigned long nmb, int base);
char			*ft_convert4(size_t nmb, int base);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *s1);
char			*ft_itoa(int n);
char			*convert2(char *a, unsigned int n, int len);
char			*ft_itoa2(unsigned int n);
int				ft_check_flag(const char *input, t_option *lst, int j);
int				ft_check_width(const char *input,
					t_option *lst, va_list *arg, int j);
int				ft_check_precision(const char *input,
					t_option *lst, va_list *arg, int j);
int				ft_char(t_option *lst, va_list *arg, int j);
int				ft_string(t_option *lst, va_list *arg, int j);
void			ft_check_neg_int(t_option *lst, int i);
void			ft_check_int(t_option *lst, int len, int i);
void			ft_check_flag_int(t_option *lst);
void			ft_check_precision_int(t_option *lst, int i);
void			ft_check_width_int(t_option *lst, int len, int i);
int				ft_int(t_option *lst, va_list *arg, int j);
void			ft_check_hex(t_option *lst, int len);
void			ft_check_precision_hex(t_option *lst, int i);
void			ft_check_flag_hex(t_option *lst);
int				ft_hex_lower(t_option *lst, va_list *arg, int j);
int				ft_hex_upper(t_option *lst, va_list *arg, int j);
void			ft_check_unsigned(t_option *lst, int len);
void			ft_check_flag_unsigned(t_option *lst);
void			ft_check_precision_unsigned(t_option *lst, int i);
void			ft_check_width_unsigned(t_option *lst, int len);
int				ft_unsigned_int(t_option *lst, va_list *arg, int j);
void			ft_check_pointer(int i, t_option *lst);
void			ft_check_flag_pointer(t_option *lst);
int				ft_pointer(t_option *lst, va_list *arg, int j);
int				ft_percent(t_option *lst, int j);
void			ft_neg_width(t_option *lst);
void			ft_neg_precision(t_option *lst);
void			ft_check_type(const char *input,
					t_option *lst, va_list *arg, int j);
int				ft_check_all(const char *input,
					t_option *lst, va_list *arg, int j);
int				ft_printf(const char *input, ...);

#endif

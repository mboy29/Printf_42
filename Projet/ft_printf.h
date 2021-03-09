/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:06:37 by mboy              #+#    #+#             */
/*   Updated: 2021/03/09 08:40:46 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

typedef	struct	s_flags
{
	int			printed;
	int			type;
	int			minus;
	int			width;
	int			zero;
	int			dot;
	int			star;
}				t_flags;

int				ft_printf(const char *arg, ...);
int				ft_conv(int c, t_flags flags, va_list list);
int				ft_flags(const char *arg, int i, t_flags *flags, va_list list);
int				ft_is_in_flags_list(int c);
int				ft_is_in_type_list(int c);
t_flags			ft_flags_width(char c, t_flags flags);
t_flags			ft_flags_minus(t_flags flags);
t_flags			ft_flags_star(va_list list, t_flags flags);
int				ft_flags_dot(const char *arg, int start,
								t_flags *flags, va_list list);
int				ft_add(int width, int minus, int has_zero);
int				ft_print(char *str, int prec);
int				ft_print_char(char c, t_flags flags);
int				ft_print_str(char *str, t_flags flags);
int				ft_print_int(int n, t_flags flags);
int				ft_print_unint(unsigned int n, t_flags flags);
int				ft_print_hex(unsigned int n, int lower, t_flags flags);
int				ft_print_ptr(unsigned long long n, t_flags flags);
int				ft_print_pct(t_flags flags);
char			*ft_u_itoa(unsigned int n);
char			*ft_base(unsigned long long n, int base);

#endif

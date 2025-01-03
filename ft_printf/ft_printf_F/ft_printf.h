/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:17:21 by amismail          #+#    #+#             */
/*   Updated: 2024/10/12 16:07:57 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		definer(const char **str, va_list arglist);
int		ft_putu(unsigned int n);
int		ft_puthex(unsigned int num, int flag);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_tolower(int c);
int		ft_putp(unsigned long num, int flag);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif

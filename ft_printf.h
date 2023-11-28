/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phabets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:54:56 by phabets           #+#    #+#             */
/*   Updated: 2022/01/10 16:13:57 by phabets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_ucount(unsigned int n);
char	*ft_utoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
int		ft_printchar(int c);
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);
int		ft_ptr_count(unsigned long ptr);
void	ft_put_ptr(unsigned long ptr);
int		ft_print_ptr(unsigned long ptr);
int		ft_putstr(char *str);
int		ft_putstrlen(char *str);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		ft_print_hex(unsigned int n, const char format);
char	*ft_itoa(int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phabets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:33:02 by phabets           #+#    #+#             */
/*   Updated: 2022/01/10 15:36:32 by phabets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	int	verif;

	verif = write(1, &c, 1);
	if (verif < 0)
		return (-1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == '%')
		len += write(1, "%", 1);
	else if (format == 's')
		len += ft_putstrlen(va_arg(args, char *));
	else if (format == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'd')
		len += ft_printnbr(va_arg(args, long int));
	else if (format == 'X' || format == 'x')
		len += ft_print_hex((va_arg(args, unsigned int)), format);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
		{
			len += ft_printchar(str[i]);
			if (len < 0)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (len);
}

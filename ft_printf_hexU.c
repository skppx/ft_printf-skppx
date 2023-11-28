/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexU.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phabets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:55:19 by phabets           #+#    #+#             */
/*   Updated: 2022/01/10 16:00:04 by phabets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_count(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_put_hexu(unsigned int n)
{
	int	verif;

	if (n >= 16)
	{
		ft_put_hexu(n / 16);
		ft_put_hexu(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			verif = ft_printchar(n + '0');
			if (verif < 0)
				return (-1);
		}
		else
		{
			verif = ft_printchar(n - 10 + 'A');
			if (verif < 0)
				return (-1);
		}
	}
	return (1);
}

int	ft_put_hexl(unsigned int n)
{
	int	verif;

	if (n >= 16)
	{
		ft_put_hexl(n / 16);
		ft_put_hexl(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			verif = ft_printchar(n + '0');
			if (verif < 0)
				return (-1);
		}
		else
		{
			verif = ft_printchar(n - 10 + 'a');
			if (verif < 0)
				return (-1);
		}
	}
	return (1);
}

int	ft_print_hex(unsigned int n, const char format)
{
	int	len;
	int	verif;

	len = 0;
	if (n == 0)
	{
		len += write (1, "0", 1);
		if (len < 0)
			return (-1);
	}
	else if (format == 'X')
	{
		verif = ft_put_hexu(n);
		if (verif < 0)
			return (-1);
		len += ft_hex_count(n);
	}
	else if (format == 'x')
	{
		verif = ft_put_hexl(n);
		if (verif < 0)
			return (-1);
		len += ft_hex_count(n);
	}
	return (len);
}

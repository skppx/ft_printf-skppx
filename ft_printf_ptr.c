/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phabets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:52:52 by phabets           #+#    #+#             */
/*   Updated: 2022/01/10 16:05:44 by phabets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_count(unsigned long ptr)
{
	int	count;

	count = 0 ;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		count++;
	}
	return (count);
}

void	ft_put_ptr(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_printchar((ptr + '0'));
		else
			ft_printchar((ptr - 10 + 'a'));
	}
}

int	ft_print_ptr(unsigned long ptr)
{
	int	len;

	len = write(1, "0x", 2);
	if (len < 0)
		return (-1);
	else if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		len += ft_ptr_count(ptr);
	}
	return (len);
}

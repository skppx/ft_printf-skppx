/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phabets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:46:26 by phabets           #+#    #+#             */
/*   Updated: 2022/01/10 15:47:39 by phabets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ucount(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	long int	_n;
	int			len;
	char		*str;

	_n = n;
	len = ft_ucount(_n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = ((_n % 10) + '0');
		_n = _n / 10;
		len--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	num = ft_utoa(n);
	len = ft_putstrlen(num);
	free(num);
	return (len);
}

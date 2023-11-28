/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phabets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:57:58 by phabets           #+#    #+#             */
/*   Updated: 2022/01/10 15:58:53 by phabets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	verif;

	i = 0;
	while (str[i])
	{
		verif = write(1, &str[i], 1);
		if (verif < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putstrlen(char *str)
{
	int	i;
	int	verif;

	i = 0;
	if (!str)
	{
		verif = ft_putstr("(null)");
		if (verif < 0)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		verif = write(1, &str[i], 1);
		if (verif <= 0)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	len = ft_putstrlen(num);
	free(num);
	return (len);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

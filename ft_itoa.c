/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phabets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:36:36 by phabets           #+#    #+#             */
/*   Updated: 2022/01/10 16:16:14 by phabets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_count(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	_n;
	int			len;
	char		*str;

	_n = n;
	len = ft_count(_n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (_n < 0)
		_n = _n * -1;
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = ((_n % 10) + '0');
		_n = _n / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:29:20 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/09 17:00:05 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numbers(int n)
{
	int c;

	c = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char		*ft_itoa(int n)
{
	int		num;
	int		sign;
	char	*res;

	sign = (n < 0) ? 1 : 0;
	num = ft_numbers(n);
	if (!(res = ft_strnew((size_t)(num + sign))))
		return (res);
	if (sign)
		res[0] = '-';
	else if (n > 0)
		num--;
	else
		res[0] = '0';
	while (n)
	{
		if (n > 0)
			res[num] = '0' + (n % 10);
		else
			res[num] = '0' + -(n % 10);
		n = n / 10;
		num--;
	}
	return (res);
}

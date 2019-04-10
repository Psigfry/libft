/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:58:18 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/08 14:12:25 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	a;
	char	*b;

	if (!(b = ft_memalloc(size + 1)))
		return (NULL);
	a = 0;
	while (a < size)
		b[a++] = '\0';
	return (b);
}
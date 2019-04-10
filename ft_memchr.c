/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:03:55 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/06 14:20:04 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*j;

	i = 0;
	j = (unsigned char*)s;
	while (++i <= n)
		if (*(j++) == (unsigned char)c)
			return ((void*)--j);
	return (0);
}

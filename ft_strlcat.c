/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:30:14 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/05 13:01:49 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	j = -1;
	while (dst[i] && i < size)
		++i;
	r = ft_strlen(src);
	while ((src[++j]) && ((i + j + 1) < size))
		dst[i + j] = src[j];
	if (i != size)
		dst[i + j] = '\0';
	return (i + r);
}

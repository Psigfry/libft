/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:50:11 by psigfry           #+#    #+#             */
/*   Updated: 2019/04/10 13:04:00 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*c;

	if (!s || !(c = ft_memalloc(len + 1)))
		return (NULL);
	c = ft_strncpy(c, (char*)s + start, len);
	return (c);
}
